from flask import Flask, render_template, request, jsonify
import subprocess, os, json, shutil

app = Flask(__name__, template_folder='templates', static_folder='static')

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
SRC_DIR = BASE_DIR
LEXICAL_BIN_PATH = os.path.join(SRC_DIR, 'bin', 'lexer')
SYNTAX_BIN_PATH = os.path.join(SRC_DIR, 'bin', 'syntax')
TEMP_C_PATH = os.path.join(BASE_DIR, 'temp.c')
TOKENS_PATH = os.path.join(SRC_DIR, 'tokens.txt')
SYMBOL_TABLE_PATH = os.path.join(SRC_DIR, 'symbol_table.json')
SEMANTIC_BIN_PATH  = os.path.join(SRC_DIR, 'bin', 'semantic')
PARSETREE_BIN_PATH = os.path.join(SRC_DIR, 'bin', 'parseTree')

# where semantic.txt lives (we assume it's created next to server.py)
SEMANTIC_OUTPUT_PATH = os.path.join(BASE_DIR, 'semantic.txt')

# parseTree produces a .dot & .png next to server.py
PARSETREE_PNG = os.path.join(BASE_DIR, 'parse_tree.png')

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/analyze', methods=['POST'])
def analyze():
    code = request.form.get('code')
    if not code:
        return jsonify({"error": "No code provided"}), 400

    try:
        with open(TEMP_C_PATH, 'w') as f:
            f.write(code)
    except Exception as e:
        return jsonify({"error": f"Failed to write temp.c: {str(e)}"}), 500

    try:
        result = subprocess.run(
            [LEXICAL_BIN_PATH, TEMP_C_PATH],
            cwd=SRC_DIR,
            capture_output=True,
            text=True,
            timeout=10
        )
        if result.returncode != 0:
            return jsonify({"error": f"Lexical analysis failed: {result.stderr}"}), 500
    except Exception as e:
        return jsonify({"error": str(e)}), 500

    try:
        with open(TOKENS_PATH, 'r') as f:
            tokens = [line.strip() for line in f.readlines()]
        with open(SYMBOL_TABLE_PATH, 'r') as f:
            symbol_table = json.load(f)
    except Exception as e:
        return jsonify({"error": f"Error reading output files: {str(e)}"}), 500
    return jsonify({
        "tokens": tokens,
        "symbol_table": symbol_table
    })

@app.route('/syntax', methods=['POST'])
def syntax_analysis():
    code = request.form.get('code')
    if not code:
        return jsonify({"error": "No code provided"}), 400

    try:
        with open(TEMP_C_PATH, 'w') as f:
            f.write(code)
    except Exception as e:
        return jsonify({"error": f"Failed to write temp.c: {str(e)}"}), 500

    try:
        result = subprocess.run(
            [SYNTAX_BIN_PATH, TEMP_C_PATH],
            cwd=SRC_DIR,
            capture_output=True,
            text=True,
            timeout=10
        )
        output = result.stdout.strip()
        if result.returncode != 0:
            return jsonify({"error": "Syntax analysis failed", "details": result.stderr.strip()}), 500
    except Exception as e:
        return jsonify({"error": str(e)}), 500

    return jsonify({
        "syntax_output": output
    })

@app.route('/semantic', methods=['POST'])
def semantic_analysis():
    code = request.form.get('code')
    if not code:
        return jsonify({"error": "No code provided"}), 400

    code = code.replace('\r\n', '\n').replace('\r', '\n')
    # write the temp.c
    with open(TEMP_C_PATH, 'w') as f:
        f.write(code)

    # run semantic binary
    result = subprocess.run(
        [SEMANTIC_BIN_PATH, TEMP_C_PATH],
        cwd=SRC_DIR,
        capture_output=True,
        text=True,
        timeout=10
    )
    if result.returncode != 0:
        return jsonify({"error": result.stderr.strip()}), 500

    # read the semantic.txt
    try:
        with open(SEMANTIC_OUTPUT_PATH) as f:
            semantic_output = f.read()
    except Exception as e:
        return jsonify({"error": f"Cannot read semantic.txt: {e}"}), 500
    
    try:
        with open(os.path.join(BASE_DIR, 'symbol_table_semantic.json')) as f:
            semantic_table = json.load(f)
    except Exception as e:
        return jsonify({"error": f"Failed to load semantic table: {e}"}), 500

    return jsonify({
        "semantic_output": semantic_output,
        "semantic_symbols": semantic_table
    })


@app.route('/parse-tree', methods=['POST'])
def parse_tree():
    code = request.form.get('code')
    if not code:
        return jsonify({"error": "No code provided"}), 400
    code = code.replace('\r\n', '\n').replace('\r', '\n')
    # write the temp.c
    with open(TEMP_C_PATH, 'w') as f:
        f.write(code)

    # run parseTree binary
    result = subprocess.run(
        [PARSETREE_BIN_PATH, TEMP_C_PATH],
        cwd=SRC_DIR,
        capture_output=True,
        text=True,
        timeout=10
    )
    if result.returncode != 0:
        return jsonify({"error": result.stderr.strip()}), 500

    # move the generated PNG into static folder so it can be served
    try:
        dst = os.path.join(app.static_folder, 'parse_tree.png')
        shutil.move(PARSETREE_PNG, dst)
    except Exception as e:
        return jsonify({"error": f"Failed to move PNG: {e}"}), 500

    # return the URL where the front end can fetch it
    return jsonify({ "parse_tree_url": '/static/parse_tree.png' })


if __name__ == '__main__':
    app.run(debug=True)
