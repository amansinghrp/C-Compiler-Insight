from flask import Flask, request, jsonify
from flask_cors import CORS
import subprocess
import os
import json

app = Flask(__name__)
CORS(app)

# Absolute path configuration
ROOT_DIR = r"D:\Study\College\VI Sem\CD PBL\C-Compiler-Insights"
COMPILER_PATH = os.path.join(ROOT_DIR, "src", "bin", "compiler.exe")
INPUT_DIR = os.path.join(ROOT_DIR, "backend", "temp")
OUTPUT_DIR = os.path.join(ROOT_DIR, "src", "1_Lexical")

# Create directories if needed
os.makedirs(INPUT_DIR, exist_ok=True)
os.makedirs(OUTPUT_DIR, exist_ok=True)

@app.route('/analyze', methods=['POST'])
def analyze():
    try:
        # Clean previous files
        input_file = os.path.join(INPUT_DIR, "temp.c")
        tokens_path = os.path.join(OUTPUT_DIR, "tokens.txt")
        symbols_path = os.path.join(OUTPUT_DIR, "symbol_table.json")
        
        for path in [input_file, tokens_path, symbols_path]:
            if os.path.exists(path):
                os.remove(path)

        # Save input code
        with open(input_file, 'w') as f:
            f.write(request.json['code'])

        # Execute compiler
        result = subprocess.run(
            [COMPILER_PATH, input_file],
            capture_output=True,
            text=True,
            cwd=OUTPUT_DIR  # Output files go here
        )

        # Handle compiler errors
        if result.returncode != 0:
            return jsonify({
                "error": f"Compiler Error: {result.stderr}",
                "output": result.stdout
            }), 500

        # Parse tokens.txt (tab-separated)
        tokens = []
        if os.path.exists(tokens_path):
            with open(tokens_path, 'r') as f:
                tokens = [{
                    "token": parts[0],
                    "type": parts[1],
                    "line": parts[2]
                } for line in f if (parts := line.strip().split('\t')) and len(parts) >= 3]

        # Parse symbol_table.json
        symbols = []
        if os.path.exists(symbols_path):
            with open(symbols_path, 'r') as f:
                symbols = json.load(f)

        return jsonify({
            "tokens": tokens,
            "symbols": symbols,
            "output": result.stdout
        })

    except Exception as e:
        return jsonify({
            "error": f"Server Error: {str(e)}"
        }), 500

if __name__ == '__main__':
    app.run(port=5000, debug=True)