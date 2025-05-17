function runAllPhases() {
  runLexical();
  runSyntax();
  runSemantic();
}

function runLexical() {
  const code = document.getElementById("c-code").value;
  // Call backend / simulation logic
  const tokens = mockLexicalAnalyzer(code); // mock function
  displayTokens(tokens);
}

function runSyntax() {
  // Use parse tree from your backend
  const treeData = mockSyntaxAnalyzer();
  displayParseTree(treeData);
}

function runSemantic() {
  const table = mockSemanticAnalyzer();
  displaySymbolTable(table);
}

function displayTokens(tokens) {
  const container = document.getElementById("tokens-container");
  container.innerHTML = "<table><tr><th>Lexeme</th><th>Token</th></tr>" +
    tokens.map(t => `<tr><td>${t.lexeme}</td><td>${t.token}</td></tr>`).join("") +
    "</table>";
}

function displayParseTree(tree) {
  const container = document.getElementById("parse-tree-container");
  container.innerHTML = JSON.stringify(tree, null, 2); // Replace with tree renderer
}

function displaySymbolTable(table) {
  const container = document.getElementById("symbol-table-container");
  container.innerHTML = "<table><tr><th>Identifier</th><th>Type</th></tr>" +
    table.map(row => `<tr><td>${row.name}</td><td>${row.type}</td></tr>`).join("") +
    "</table>";
}
