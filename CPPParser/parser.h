
#ifndef __PARSER_H__
#define __PARSER_H__

#define IDENTIFIER 256
#define INTEGER 257
#define FLOATING 258
#define CHARACTER 259
#define STRING 260
#define TYPEDEF_NAME 261
#define NAMESPACE_NAME 262
#define CLASS_NAME 263
#define ENUM_NAME 264
#define TEMPLATE_NAME 265
#define ELLIPSIS 266
#define COLONCOLON 267
#define DOTSTAR 268
#define ADDEQ 269
#define SUBEQ 270
#define MULEQ 271
#define DIVEQ 272
#define MODEQ 273
#define XOREQ 274
#define ANDEQ 275
#define OREQ 276
#define SL 277
#define SR 278
#define SREQ 279
#define SLEQ 280
#define EQ 281
#define NOTEQ 282
#define LTEQ 283
#define GTEQ 284
#define ANDAND 285
#define OROR 286
#define PLUSPLUS 287
#define MINUSMINUS 288
#define ARROWSTAR 289
#define ARROW 290
#define ASM 291
#define AUTO 292
#define BOOL 293
#define BREAK 294
#define CASE 295
#define CATCH 296
#define CHAR 297
#define CLASS 298
#define CONST 299
#define CONST_CAST 300
#define CONTINUE 301
#define DEFAULT 302
#define DELETE 303
#define DO 304
#define DOUBLE 305
#define DYNAMIC_CAST 306
#define ELSE 307
#define ENUM 308
#define EXPLICIT 309
#define EXPORT 310
#define EXTERN 311
#define FALSE 312
#define FLOAT 313
#define FOR 314
#define FRIEND 315
#define GOTO 316
#define IF 317
#define INLINE 318
#define INT 319
#define LONG 320
#define MUTABLE 321
#define NAMESPACE 322
#define NEW 323
#define OPERATOR 324
#define PRIVATE 325
#define PROTECTED 326
#define PUBLIC 327
#define REGISTER 328
#define REINTERPRET_CAST 329
#define RETURN 330
#define SHORT 331
#define SIGNED 332
#define SIZEOF 333
#define STATIC 334
#define STATIC_CAST 335
#define STRUCT 336
#define SWITCH 337
#define TEMPLATE 338
#define THIS 339
#define THROW 340
#define TRUE 341
#define TRY 342
#define TYPEDEF 343
#define TYPEID 344
#define TYPENAME 345
#define UNION 346
#define UNSIGNED 347
#define USING 348
#define VIRTUAL 349
#define VOID 350
#define VOLATILE 351
#define WCHAR_T 352
#define WHILE 353

typedef int token_t;

typedef void * node_t;

bool cpp_parser_typedef_name(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_namespace_name(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_original_namespace_name(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_namespace_alias(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_class_name(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_enum_name(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_template_name(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_identifier(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_literal(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_integer_literal(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_character_literal(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_floating_literal(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_string_literal(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_boolean_literal(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_translation_unit(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_primary_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_id_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_unqualified_id(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_qualified_id(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_nested_name_specifier(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_class_or_namespace_name(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_postfix_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_expression_list(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_pseudo_destructor_name(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_unary_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_unary_operator(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_new_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_new_placement(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_new_type_id(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_new_declarator(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_direct_new_declarator(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_new_initializer(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_delete_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_cast_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_pm_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_multiplicative_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_additive_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_shift_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_relational_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_equality_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_and_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_exclusive_or_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_inclusive_or_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_logical_and_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_logical_or_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_conditional_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_assignment_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_assignment_operator(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_constant_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_statement(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_labeled_statement(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_expression_statement(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_compound_statement(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_statement_seq(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_selection_statement(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_condition(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_iteration_statement(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_for_init_statement(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_jump_statement(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_declaration_statement(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_declaration_seq(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_declaration(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_block_declaration(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_simple_declaration(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_decl_specifier(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_decl_specifier_seq(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_storage_class_specifier(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_function_specifier(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_type_specifier(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_simple_type_specifier(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_type_name(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_elaborated_type_specifier(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_enum_specifier(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_enumerator_list(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_enumerator_definition(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_enumerator(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_namespace_definition(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_named_namespace_definition(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_original_namespace_definition(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_extension_namespace_definition(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_unnamed_namespace_definition(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_namespace_body(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_namespace_alias_definition(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_qualified_namespace_specifier(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_using_declaration(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_using_directive(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_asm_definition(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_linkage_specification(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_init_declarator_list(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_init_declarator(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_declarator(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_direct_declarator(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_ptr_operator(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_cv_qualifier_seq(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_cv_qualifier(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_declarator_id(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_type_id(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_type_specifier_seq(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_abstract_declarator(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_direct_abstract_declarator(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_parameter_declaration_clause(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_parameter_declaration_list(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_parameter_declaration(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_function_definition(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_function_body(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_initializer(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_initializer_clause(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_initializer_list(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_class_specifier(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_class_head(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_class_key(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_member_specification(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_member_declaration(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_member_declarator_list(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_member_declarator(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_pure_specifier(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_constant_initializer(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_base_clause(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_base_specifier_list(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_base_specifier(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_access_specifier(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_conversion_function_id(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_conversion_type_id(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_conversion_declarator(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_ctor_initializer(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_mem_initializer_list(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_mem_initializer(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_mem_initializer_id(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_operator_function_id(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_operator(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_template_declaration(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_template_parameter_list(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_template_parameter(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_type_parameter(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_template_id(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_template_argument_list(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_template_argument(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_explicit_instantiation(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_explicit_specialization(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_try_block(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_function_try_block(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_handler_seq(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_handler(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_exception_declaration(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_throw_expression(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_exception_specification(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_type_id_list(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_declaration_seq_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_TEMPLATE_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_nested_name_specifier_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_expression_list_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_COLONCOLON_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_new_placement_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_new_initializer_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_new_declarator_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_expression_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_statement_seq_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_condition_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_decl_specifier_seq_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_init_declarator_list_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_identifier_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_enumerator_list_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_TYPENAME_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_initializer_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_cv_qualifier_seq_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_exception_specification_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_constant_expression_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_abstract_declarator_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_type_specifier_seq_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_direct_abstract_declarator_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_parameter_declaration_list_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_ELLIPSIS_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_ctor_initializer_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_COMMA_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_member_specification_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_base_clause_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_member_declarator_list_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_SEMICOLON_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_pure_specifier_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_constant_initializer_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_access_specifier_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_VIRTUAL_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_conversion_declarator_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_EXPORT_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_handler_seq_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_assignment_expression_opt(const token_t * tokens, int & token_i, node_t & node);
bool cpp_parser_type_id_list_opt(const token_t * tokens, int & token_i, node_t & node);

#endif // __PARSER_H__
