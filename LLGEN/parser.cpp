/*
 * generated by llgen: Thu Jun 12 20:36:31 2008
 */

#include "parser.h"

template <int token>
bool cpp_parser_shift_token(const token_t * tokens, int & token_i, node_t & node)
{
    if(token == tokens[token_i].getType())
    {
		node = ll::AstNodePtr(new ll::AstNode(tokens[token_i].getText(), &tokens[token_i]));
		token_i++;
        return true;
    }

	ll::set_last_error_except_existed("syntax error, need " + ll::token_type_to_str(token), &tokens[token_i]);
    return false;
}

/*******************************************************************************
 *    translate_unit:
 *        token_seq_opt PERCENTPERCENT production_seq_opt PERCENTPERCENT 
 *******************************************************************************/

bool cpp_parser_translate_unit(const token_t * tokens, int & token_i, node_t & node)
{
	node_t node1;
    if(cpp_parser_token_seq_opt(tokens, token_i, node1))
    {
		node_t node2;
        if(cpp_parser_shift_token<PERCENTPERCENT>(tokens, token_i, node2))
        {
			node_t node3;
            if(cpp_parser_production_seq_opt(tokens, token_i, node3))
            {
				node_t node4;
                if(cpp_parser_shift_token<PERCENTPERCENT>(tokens, token_i, node4))
                {
					assert("tokens" == node1->getText());
					assert("productions" == node3->getText());
					node = ll::AstNodePtr(new ll::AstNode("root"));
					node->pushChild(node1);
					node->pushChild(node3);
                    return true;
                }
            }
        }
    }
    return false;
}

/*******************************************************************************
 *    token_seq:
 *        PERCENTTOKEN identifier_seq token_seq_opt 
 *******************************************************************************/

bool cpp_parser_token_seq(const token_t * tokens, int & token_i, node_t & node)
{
	node_t node1;
    if(cpp_parser_shift_token<PERCENTTOKEN>(tokens, token_i, node1))
    {
		node_t node2;
        if(cpp_parser_identifier_seq(tokens, token_i, node2))
        {
			node_t node3;
            if(cpp_parser_token_seq_opt(tokens, token_i, node3))
            {
				assert("identifiers" == node2->getText());
				assert("tokens" == node3->getText());
				node = ll::AstNodePtr(new ll::AstNode("tokens"));
				node->pushChildList(node2->m_childs.begin(), node2->m_childs.end());
				node->pushChildList(node3->m_childs.begin(), node3->m_childs.end());
                return true;
            }
        }
    }
    return false;
}

/*******************************************************************************
 *    token_seq_opt:
 *        <<EMPTY>> 
 *        | token_seq 
 *******************************************************************************/

bool cpp_parser_token_seq_opt(const token_t * tokens, int & token_i, node_t & node)
{
	int current_i = token_i;
	node_t node1;
    switch(tokens[token_i].getType())
    {
    case PERCENTTOKEN:
        {
            if(cpp_parser_token_seq(tokens, token_i, node1))
            {
				node = node1;
                return true;
            }
            break;
        }

    default:
		node = ll::AstNodePtr(new ll::AstNode("tokens"));
        break;
    }

	token_i = current_i;
    return true;
}

/*******************************************************************************
 *    identifier_seq:
 *        IDENTIFIER identifier_seq_opt 
 *******************************************************************************/

bool cpp_parser_identifier_seq(const token_t * tokens, int & token_i, node_t & node)
{
	node_t node1;
    if(cpp_parser_shift_token<IDENTIFIER>(tokens, token_i, node1))
    {
		node_t node2;
        if(cpp_parser_identifier_seq_opt(tokens, token_i, node2))
        {
			assert("identifiers" == node2->getText());
			node = ll::AstNodePtr(new ll::AstNode("identifiers"));
			node->pushChild(node1);
			node->pushChildList(node2->m_childs.begin(), node2->m_childs.end());
            return true;
        }
    }
    return false;
}

/*******************************************************************************
 *    identifier_seq_opt:
 *        <<EMPTY>> 
 *        | identifier_seq 
 *******************************************************************************/

bool cpp_parser_identifier_seq_opt(const token_t * tokens, int & token_i, node_t & node)
{
	int current_i = token_i;
	node_t node1;
    switch(tokens[token_i].getType())
    {
    case IDENTIFIER:
        {
            if(cpp_parser_identifier_seq(tokens, token_i, node1))
            {
				node = node1;
                return true;
            }
            break;
        }

    default:
		node = ll::AstNodePtr(new ll::AstNode("identifiers"));
        break;
    }

	token_i = current_i;
    return true;
}

/*******************************************************************************
 *    production_seq:
 *        IDENTIFIER ':' production_rhs production_seq_opt 
 *******************************************************************************/

bool cpp_parser_production_seq(const token_t * tokens, int & token_i, node_t & node)
{
	node_t node1;
    if(cpp_parser_shift_token<IDENTIFIER>(tokens, token_i, node1))
    {
		node_t node2;
        if(cpp_parser_shift_token<':'>(tokens, token_i, node2))
        {
			node_t node3;
            if(cpp_parser_production_rhs(tokens, token_i, node3))
            {
				node_t node4;
                if(cpp_parser_production_seq_opt(tokens, token_i, node4))
                {
					assert("rhs" == node3->getText());
					assert("productions" == node4->getText());
					node1->pushChildList(node3->m_childs.begin(), node3->m_childs.end());
					node = ll::AstNodePtr(new ll::AstNode("productions"));
					node->pushChild(node1);
					node->pushChildList(node4->m_childs.begin(), node4->m_childs.end());
                    return true;
                }
            }
        }
    }
    return false;
}

/*******************************************************************************
 *    production_seq_opt:
 *        <<EMPTY>> 
 *        | production_seq 
 *******************************************************************************/

bool cpp_parser_production_seq_opt(const token_t * tokens, int & token_i, node_t & node)
{
	int current_i = token_i;
	node_t node1;
    switch(tokens[token_i].getType())
    {
    case IDENTIFIER:
        {
            if(cpp_parser_production_seq(tokens, token_i, node1))
            {
				node = node1;
                return true;
            }
            break;
        }

    default:
		node = ll::AstNodePtr(new ll::AstNode("productions"));
        break;
    }

	token_i = current_i;
    return true;
}

/*******************************************************************************
 *    production_rhs:
 *        symbol_seq_opt '|' production_rhs 
 *        | symbol_seq_opt ';' 
 *******************************************************************************/

bool cpp_parser_production_rhs(const token_t * tokens, int & token_i, node_t & node)
{
	node_t node1;
    if(cpp_parser_symbol_seq_opt(tokens, token_i, node1))
    {
		node_t node2;
        switch(tokens[token_i].getType())
        {
        case ';':
            {
                if(cpp_parser_shift_token<';'>(tokens, token_i, node2))
                {
					assert("symbols" == node1->getText());
					node = ll::AstNodePtr(new ll::AstNode("rhs"));
					node->pushChild(node1);
                    return true;
                }
                break;
            }

        case '|':
            {
                if(cpp_parser_shift_token<'|'>(tokens, token_i, node2))
                {
					node_t node3;
                    if(cpp_parser_production_rhs(tokens, token_i, node3))
                    {
						assert("symbols" == node1->getText());
						assert("rhs" == node3->getText());
						node = ll::AstNodePtr(new ll::AstNode("rhs"));
						node->pushChild(node1);
						node->pushChildList(node3->m_childs.begin(), node3->m_childs.end());
                        return true;
                    }
                }
                break;
            }

        default:
			ll::set_last_error_except_existed("syntax error, need ';' or '|'", &tokens[token_i]);
            break;
        }
    }
    return false;
}

/*******************************************************************************
 *    symbol_seq:
 *        symbol symbol_seq_opt 
 *******************************************************************************/

bool cpp_parser_symbol_seq(const token_t * tokens, int & token_i, node_t & node)
{
	node_t node1;
    if(cpp_parser_symbol(tokens, token_i, node1))
    {
		node_t node2;
        if(cpp_parser_symbol_seq_opt(tokens, token_i, node2))
        {
			assert("symbols" == node2->getText());
			node = ll::AstNodePtr(new ll::AstNode("symbols"));
			node->pushChild(node1);
			node->pushChildList(node2->m_childs.begin(), node2->m_childs.end());
            return true;
        }
    }
    return false;
}

/*******************************************************************************
 *    symbol_seq_opt:
 *        <<EMPTY>> 
 *        | symbol_seq 
 *******************************************************************************/

bool cpp_parser_symbol_seq_opt(const token_t * tokens, int & token_i, node_t & node)
{
	int current_i = token_i;
	node_t node1;
    switch(tokens[token_i].getType())
    {
    case CHARACTER:
    case IDENTIFIER:
        {
            if(cpp_parser_symbol_seq(tokens, token_i, node1))
            {
				node = node1;
                return true;
            }
            break;
        }

    default:
		node = ll::AstNodePtr(new ll::AstNode("symbols"));
        break;
    }

	token_i = current_i;
    return true;
}

/*******************************************************************************
 *    symbol:
 *        IDENTIFIER 
 *        | CHARACTER 
 *******************************************************************************/

bool cpp_parser_symbol(const token_t * tokens, int & token_i, node_t & node)
{
	node_t node1;
    switch(tokens[token_i].getType())
    {
    case CHARACTER:
        {
            if(cpp_parser_shift_token<CHARACTER>(tokens, token_i, node1))
            {
				node = node1;
                return true;
            }
            break;
        }

    case IDENTIFIER:
        {
            if(cpp_parser_shift_token<IDENTIFIER>(tokens, token_i, node1))
            {
				node = node1;
                return true;
            }
            break;
        }

    default:
		ll::set_last_error_except_existed("syntax error, need IDENTTIFIER or CHARACTER", &tokens[token_i]);
        break;
    }
    return false;
}
