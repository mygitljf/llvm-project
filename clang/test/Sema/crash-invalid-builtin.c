// RUN: %clang_cc1 -triple=x86_64-apple-darwin -fsyntax-only -verify %s
// PR23086

__builtin_isinf(...); // expected-error {{type specifier missing, defaults to 'int'}} expected-error {{ISO C requires a named parameter before '...'}} // expected-error {{cannot redeclare builtin function '__builtin_isinf'}} // expected-note {{'__builtin_isinf' is a builtin with type 'int ()'}}

char nanf_wide = __builtin_nanf(L""); // expected-error {{incompatible pointer types passing 'int[1]' to parameter of type 'const char *'}} expected-error {{initializer element is not a compile-time constant}}
