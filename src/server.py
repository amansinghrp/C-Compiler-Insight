from flask import Flask, render_template, request, jsonify
import subprocess, os, json

app = Flask(__name__, template_folder='templates', static_folder='static')

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
SRC_DIR = BASE_DIR
BIN_PATH = os.path.join(SRC_DIR, 'bin', 'compiler')
TEMP_C_PATH = os.path.join(BASE_DIR, 'temp.c')
TOKENS_PATH = os.path.join(SRC_DIR, 'tokens.txt')
SYMBOL_TABLE_PATH = os.path.join(SRC_DIR, 'symbol_table.json')

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/analyze', methods=['POST'])
def analyze():
    code = request.form.get('code')
    if not code:
        return jsonify({"error": "No code provided"}), 400

    # Write to temp.c
    try:
        with open(TEMP_C_PATH, 'w') as f:
            f.write(code)
    except Exception as e:
        return jsonify({"error": str(e)}), 500

    try:
        result = subprocess.run(
            [BIN_PATH, TEMP_C_PATH],
            cwd=SRC_DIR,
            capture_output=True,
            text=True,
            timeout=10
        )
        if result.returncode != 0:
            return jsonify({"error": result.stderr}), 500
    except Exception as e:
        return jsonify({"error": str(e)}), 500

    try:
        with open(TOKENS_PATH, 'r') as f:
            tokens = [line.strip() for line in f.readlines()]
        with open(SYMBOL_TABLE_PATH, 'r') as f:
            symbol_table = json.load(f)
    except Exception as e:
        return jsonify({"error": str(e)}), 500

    return jsonify({"tokens": tokens, "symbol_table": symbol_table})

if __name__ == '__main__':
    app.run(debug=True)
