module.exports = grammar({
    name: 'project',
  
    rules: {
      // TODO: add the actual grammar rules
      source_file: $ => $._expression, // repeat($._fieldExpression)),
      _expression: $ => choice(
        $.fieldCall,
        $.fieldExpression,
        $.fieldName,
        $.index,
        $.call,
        $._path,
        $.name,
        $.integer),
      _indexBaseExpression: $ => choice(
        $.fieldCall,
        $.fieldName,
        $.index,
        $.name,
        $.integer),
      // fieldExpression: $ => seq($._expression, choice($.fieldCall, $.fieldName)),
      call: $ => prec(1, seq($.name, ' ', $._expression)),
      fieldCall: $ => prec(2, seq($._expression, ':', $.name, '(', $._expression, ')')),
      fieldExpression: $ => prec(2, seq($._expression, ':', $.name)),
      fieldName: $ => seq(':', $.name),
      index: $ => seq($._indexBaseExpression, '[', $._expression, ']'),
      _path: $ => choice(
        $.relativePath,
        $.absolutePath),
        absolutePath: $ => seq(repeat1(seq('/', $.name))),
      relativePath: $ => seq($.name, repeat1(seq('/', $.name))),
      integer: $ => /[0-9]+/,
      
      name: $ => /[a-zA-Z_\.][a-zA-Z0-9_\.]*/,
      // _argExpression: $ => choice($._fieldExpression, $._expression)
    }
  });
  