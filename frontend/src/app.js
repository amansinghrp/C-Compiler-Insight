// Initialize Monaco Editor
require.config({ paths: { vs: 'https://cdnjs.cloudflare.com/ajax/libs/monaco-editor/0.36.1/min/vs' }});
require(['vs/editor/editor.main'], () => {
    window.editor = monaco.editor.create(document.getElementById('editor'), {
        value: '// Enter C code here\n#include <stdio.h>\n\nint main() {\n    int x = 42;\n    return 0;\n}',
        language: 'c',
        theme: 'vs-dark',
        automaticLayout: true
    });
});

async function analyze() {
    const code = window.editor.getValue();
    
    // Call backend/compiler
    const response = await fetch('/analyze', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ code })
    });

    const results = await response.json();
    
    // Display results
    displayTokens(results.tokens);
    displaySymbols(results.symbols);
}

function displayTokens(tokens) {
    const container = document.getElementById('tokens');
    container.innerHTML = tokens.map(token => `
        <div class="token" style="background: ${getTokenColor(token.type)}">
            ${token.value}<br>
            <small>${token.type}</small>
        </div>
    `).join('');
}

function displaySymbols(symbols) {
    const container = document.getElementById('symbols')
    container.innerHTML = `
        <table>
            <tr>
                <th>Name</th>
                <th>Type</th>
                <th>Memory Address</th>
            </tr>
            ${symbols.map(s => `
                <tr>
                    <td>${s.name}</td>
                    <td>${s.type}</td>
                    <td>${s.address}</td>
                </tr>
            `).join('')}
        </table>
    `;
}

function getTokenColor(type) {
    const colors = {
        keyword: '#ffb3ba',
        identifier: '#baffc9',
        constant: '#bae1ff',
        operator: '#ffffba',
        punctuation: '#dfd3ff'
    };
    return colors[type.toLowerCase()] || '#cccccc';
}