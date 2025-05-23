from flask import Flask, request, jsonify, render_template_string
import subprocess

app = Flask(__name__)

# Simple HTML UI template
HTML_TEMPLATE = '''
<!DOCTYPE html>
<html>
<head>
<title>Semantic Checker</title>
<style>
body { font-family: Arial, sans-serif; margin: 20px; }
textarea { width: 100%; height: 300px; font-family: monospace; font-size: 14px; }
button { padding: 10px 20px; font-size: 16px; margin-top: 10px; }
pre { background: #f0f0f0; padding: 10px; white-space: pre-wrap; }
</style>
</head>
<body>
<h2>C Semantic Semantic Error Checker</h2>
<textarea id="codeInput" placeholder="Paste your C code here..."></textarea><br/>
<button onclick="checkSemantic()">Check Semantic Errors</button>
<h3>Output:</h3>
<pre id="output"></pre>

<script>
function checkSemantic() {
    const code = document.getElementById('codeInput').value;
    document.getElementById('output').textContent = 'Checking...';

    fetch('/check', {
        method: 'POST',
        headers: {'Content-Type': 'application/json'},
        body: JSON.stringify({code: code})
    })
    .then(res => res.json())
    .then(data => {
        document.getElementById('output').textContent = data.result || 'No errors found!';
    })
    .catch(e => {
        document.getElementById('output').textContent = 'Error: ' + e.message;
    });
}
</script>
</body>
</html>
'''

@app.route('/')
def index():
    return render_template_string(HTML_TEMPLATE)

@app.route('/check', methods=['POST'])
def check():
    data = request.get_json()
    code = data.get('code', '')

    # Write code to temp file
    with open('temp_input.c', 'w') as f:
        f.write(code)

    # Run the semantic checker executable
    try:
        result = subprocess.run(['./semantic_checker', 'temp_input.c'], capture_output=True, text=True, timeout=5)
        output = result.stdout.strip()
        if output == '':
            output = 'No semantic errors found!'
    except Exception as e:
        output = f"Error running checker: {e}"

    return jsonify({'result': output})

if __name__ == '__main__':
    app.run(debug=True)
