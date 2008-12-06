
#include "parser.h"

#define GET_TOKEN_ID(tokens, token_i) tokens[token_i].getType()

#define REPORT_SHIFT_ERROR(tokens, token_i, TOKEN_ID) ll::set_last_error_except_existed("syntax error, need '" + ll::token_type_to_str(TOKEN_ID) + "'", &tokens[token_i])

#define REPORT_SWITCH_ERROR(tokens, token_i) ll::set_last_error_except_existed("syntax error, unknown token", &tokens[token_i])

bool ll_parser_shift_EMPTY(const token_t * tokens, int & token_i, node_t & node)
{
    return true;
}

template <int TOKEN_ID>
bool ll_parser_shift_token(const token_t * tokens, int & token_i, node_t & node)
{
    if(TOKEN_ID == GET_TOKEN_ID(tokens, token_i))
    {
		node = ll::AstNodePtr(new ll::AstNode(tokens[token_i].getText(), &tokens[token_i]));
        token_i++;
        return true;
    }

    REPORT_SHIFT_ERROR(tokens, token_i, TOKEN_ID);
    return false;
}

/******************************************************************************************
 * translate_unit
 *     token_seq_opt PERCENTPERCENT production_seq_opt PERCENTPERCENT 
 ******************************************************************************************/

bool ll_parser_translate_unit(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(ll_parser_token_seq_opt(tokens, token_i, node1))
    {
        node_t node2;
        if(ll_parser_shift_token<PERCENTPERCENT>(tokens, token_i, node2))
        {
            node_t node3;
            if(ll_parser_production_seq_opt(tokens, token_i, node3))
            {
                node_t node4;
                if(ll_parser_shift_token<PERCENTPERCENT>(tokens, token_i, node4))
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

/******************************************************************************************
 * token_seq
 *     PERCENTTOKEN identifier_seq token_seq_opt 
 ******************************************************************************************/

bool ll_parser_token_seq(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(ll_parser_shift_token<PERCENTTOKEN>(tokens, token_i, node1))
    {
        node_t node2;
        if(ll_parser_identifier_seq(tokens, token_i, node2))
        {
            node_t node3;
            if(ll_parser_token_seq_opt(tokens, token_i, node3))
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

/******************************************************************************************
 * token_seq_opt
 *     <<empty>>
 *     token_seq 
 ******************************************************************************************/

bool ll_parser_token_seq_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(ll_parser_shift_EMPTY(tokens, token_i, node1))
        {
			node = ll::AstNodePtr(new ll::AstNode("tokens"));
            return true;
        }
        break;

    case PERCENTTOKEN:
        if(ll_parser_token_seq(tokens, token_i, node1))
        {
			node = node1;
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * identifier_seq
 *     IDENTIFIER identifier_seq_opt 
 ******************************************************************************************/

bool ll_parser_identifier_seq(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(ll_parser_shift_token<IDENTIFIER>(tokens, token_i, node1))
    {
        node_t node2;
        if(ll_parser_identifier_seq_opt(tokens, token_i, node2))
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

/******************************************************************************************
 * identifier_seq_opt
 *     <<empty>>
 *     identifier_seq 
 ******************************************************************************************/

bool ll_parser_identifier_seq_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(ll_parser_shift_EMPTY(tokens, token_i, node1))
        {
			node = ll::AstNodePtr(new ll::AstNode("identifiers"));
            return true;
        }
        break;

    case IDENTIFIER:
        if(ll_parser_identifier_seq(tokens, token_i, node1))
        {
			node = node1;
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * production_seq
 *     IDENTIFIER ':' production_rhs production_seq_opt 
 ******************************************************************************************/

bool ll_parser_production_seq(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(ll_parser_shift_token<IDENTIFIER>(tokens, token_i, node1))
    {
        node_t node2;
        if(ll_parser_shift_token<':'>(tokens, token_i, node2))
        {
            node_t node3;
            if(ll_parser_production_rhs(tokens, token_i, node3))
            {
                node_t node4;
                if(ll_parser_production_seq_opt(tokens, token_i, node4))
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

/******************************************************************************************
 * production_seq_opt
 *     <<empty>>
 *     production_seq 
 ******************************************************************************************/

bool ll_parser_production_seq_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(ll_parser_shift_EMPTY(tokens, token_i, node1))
        {
			node = ll::AstNodePtr(new ll::AstNode("productions"));
            return true;
        }
        break;

    case IDENTIFIER:
        if(ll_parser_production_seq(tokens, token_i, node1))
        {
			node = node1;
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * production_rhs
 *     symbol_seq_opt '|' production_rhs 
 *     symbol_seq_opt ';' 
 ******************************************************************************************/

bool ll_parser_production_rhs(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(ll_parser_symbol_seq_opt(tokens, token_i, node1))
    {
        node_t node2;
        switch(GET_TOKEN_ID(tokens, token_i))
        {
        case ';':
            if(ll_parser_shift_token<';'>(tokens, token_i, node2))
            {
				assert("symbols" == node1->getText());
				node = ll::AstNodePtr(new ll::AstNode("rhs"));
				node->pushChild(node1);
                return true;
            }
            break;

        case '|':
            if(ll_parser_shift_token<'|'>(tokens, token_i, node2))
            {
                node_t node3;
                if(ll_parser_production_rhs(tokens, token_i, node3))
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

        default:
            REPORT_SWITCH_ERROR(tokens, token_i);
        }
    }
    return false;
}

/******************************************************************************************
 * symbol_seq
 *     symbol symbol_seq_opt 
 ******************************************************************************************/

bool ll_parser_symbol_seq(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(ll_parser_symbol(tokens, token_i, node1))
    {
        node_t node2;
        if(ll_parser_symbol_seq_opt(tokens, token_i, node2))
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

/******************************************************************************************
 * symbol_seq_opt
 *     <<empty>>
 *     symbol_seq 
 ******************************************************************************************/

bool ll_parser_symbol_seq_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(ll_parser_shift_EMPTY(tokens, token_i, node1))
        {
			node = ll::AstNodePtr(new ll::AstNode("symbols"));
            return true;
        }
        break;

    case CHARACTER:
    case IDENTIFIER:
        if(ll_parser_symbol_seq(tokens, token_i, node1))
        {
			node = node1;
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * symbol
 *     IDENTIFIER 
 *     CHARACTER 
 ******************************************************************************************/

bool ll_parser_symbol(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case CHARACTER:
        if(ll_parser_shift_token<CHARACTER>(tokens, token_i, node1))
        {
			node = node1;
            return true;
        }
        break;

    case IDENTIFIER:
        if(ll_parser_shift_token<IDENTIFIER>(tokens, token_i, node1))
        {
			node = node1;
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}
