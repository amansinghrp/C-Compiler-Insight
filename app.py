import subprocess
from flask import Flask, request, render_template_string

app = Flask(__name__)

HTML = '''
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <title>Code Analyzer</title>
    <style>
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background: #f4f7fa;
            color: #333;
            padding: 20px;
            max-width: 900px;
            margin: 0 auto;
        }
        h1 {
            text-align: center;
            color: #2c3e50;
        }
        form {
            margin-bottom: 20px;
        }
        textarea {
            width: 100%;
            font-family: monospace;
            font-size: 16px;
            padding: 12px;
            border-radius: 5px;
            border: 1px solid #ccc;
            resize: vertical;
            min-height: 300px;
            box-sizing: border-box;
            background: #fff;
            transition: border-color 0.3s ease;
        }
        textarea:focus {
            border-color: #2980b9;
            outline: none;
            box-shadow: 0 0 5px rgba(41, 128, 185, 0.5);
        }
        input[type="submit"] {
            background-color: #2980b9;
            color: white;
            border: none;
            padding: 12px 25px;
            font-size: 16px;
            border-radius: 5px;
            cursor: pointer;
            transition: background-color 0.3s ease;
        }
        input[type="submit"]:hover {
            background-color: #1c5980;
        }
        .output {
            background: #2c3e50;
            color: #e74c3c;
            padding: 15px;
            border-radius: 6px;
            white-space: pre-wrap;
            font-family: monospace;
            font-size: 15px;
            box-shadow: 0 0 10px rgba(231, 76, 60, 0.5);
        }
        .no-error {
            background: #27ae60;
            color: white;
            padding: 15px;
            border-radius: 6px;
            font-weight: bold;
            text-align: center;
            box-shadow: 0 0 10px rgba(39, 174, 96, 0.5);
        }
    </style>
</head>
<body>
    <h1>C Code Syntax Analyzer</h1>
    <form method="POST">
        <textarea name="code" placeholder="Paste your C code here...">{{ code }}</textarea><br/>
        <input type="submit" value="Analyze" />
    </form>

    {% if output %}
        {% if output == 'No syntax errors found.' %}
            <div class="no-error">{{ output }}</div>
        {% else %}
            <h3>Parser Output:</h3>
            <div class="output">{{ output }}</div>
        {% endif %}
    {% endif %}
</body>
</html>
'''

@app.route('/', methods=['GET', 'POST'])
def index():
    code = ''
    output = ''
    if request.method == 'POST':
        code = request.form['code']
        with open('temp.c', 'w') as f:
            f.write(code)

        # Run your parser executable on the temp file
        # Assuming `myparser` is in the same directory and executable
        result = subprocess.run(['./myparser', 'temp.c'], capture_output=True, text=True)

        # You can decide whether your parser prints errors to stdout or stderr
        # For safety, combine both outputs:
        output = result.stdout.strip() + '\n' + result.stderr.strip()
        output = output.strip()
        
        # If output is empty, assume no syntax errors
        if output == '':
            output = 'No syntax errors found.'

    return render_template_string(HTML, code=code, output=output)

if __name__ == '__main__':
    app.run(debug=True)
