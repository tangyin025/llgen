
#ifndef __PARSER_H__
#define __PARSER_H__

#include "generator.h"

typedef ll::AstToken token_t;

typedef ll::AstNodePtr node_t;

#define PERCENTPERCENT 256
#define PERCENTTOKEN 257
#define PERCENTOTHER 258
#define IDENTIFIER 259
#define CHARACTER 260

bool ll_parser_translate_unit(const token_t * tokens, int & token_i, node_t & node);
bool ll_parser_token_seq(const token_t * tokens, int & token_i, node_t & node);
bool ll_parser_token_seq_opt(const token_t * tokens, int & token_i, node_t & node);
bool ll_parser_identifier_seq(const token_t * tokens, int & token_i, node_t & node);
bool ll_parser_identifier_seq_opt(const token_t * tokens, int & token_i, node_t & node);
bool ll_parser_production_seq(const token_t * tokens, int & token_i, node_t & node);
bool ll_parser_production_seq_opt(const token_t * tokens, int & token_i, node_t & node);
bool ll_parser_production_rhs(const token_t * tokens, int & token_i, node_t & node);
bool ll_parser_symbol_seq(const token_t * tokens, int & token_i, node_t & node);
bool ll_parser_symbol_seq_opt(const token_t * tokens, int & token_i, node_t & node);
bool ll_parser_symbol(const token_t * tokens, int & token_i, node_t & node);

#endif // __PARSER_H__
