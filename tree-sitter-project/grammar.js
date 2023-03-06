module.exports = grammar({
    name: 'project',
  
    rules: {
      // TODO: add the actual grammar rules
      source_file: $ => $._expression, // repeat($._fieldExpression)),
      _expression: $ => choice(
        $.fieldCall,
        $.fieldName,
        $.index,
        $.name,
        $.integer),
      // fieldExpression: $ => seq($._expression, choice($.fieldCall, $.fieldName)),
      fieldCall: $ => seq($._expression, ':', $.name, '(', $._expression, ')'),
      fieldName: $ => seq(':', $.name),
      integer: $ => /[0-9]+/,
      name: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,
      // _argExpression: $ => choice($._fieldExpression, $._expression)
    }
  });
  