
#include "E:\VC++ .NET 2003\works\SGS\LLSolution\/CPPParser/parser.h"

#define GET_TOKEN_ID(tokens, token_i) tokens[token_i]

#define REPORT_SHIFT_ERROR(tokens, token_i, TOKEN_ID)

#define REPORT_SWITCH_ERROR(tokens, token_i)

bool cpp_parser_shift_EMPTY(const token_t * tokens, int & token_i, node_t & node)
{
    return true;
}

template <int TOKEN_ID>
bool cpp_parser_shift_token(const token_t * tokens, int & token_i, node_t & node)
{
    if(TOKEN_ID == GET_TOKEN_ID(tokens, token_i))
    {
        token_i++;
        return true;
    }

    REPORT_SHIFT_ERROR(tokens, token_i, TOKEN_ID);
    return false;
}

/******************************************************************************************
 * typedef_name
 *     TYPEDEF_NAME 
 ******************************************************************************************/

bool cpp_parser_typedef_name(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<TYPEDEF_NAME>(tokens, token_i, node1))
    {
        return true;
    }
    return false;
}

/******************************************************************************************
 * namespace_name
 *     original_namespace_name 
 *     namespace_alias 
 ******************************************************************************************/

bool cpp_parser_namespace_name(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case NAMESPACE_NAME:
        if(cpp_parser_namespace_alias(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_original_namespace_name(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * original_namespace_name
 *     NAMESPACE_NAME 
 ******************************************************************************************/

bool cpp_parser_original_namespace_name(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<NAMESPACE_NAME>(tokens, token_i, node1))
    {
        return true;
    }
    return false;
}

/******************************************************************************************
 * namespace_alias
 *     NAMESPACE_NAME 
 ******************************************************************************************/

bool cpp_parser_namespace_alias(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<NAMESPACE_NAME>(tokens, token_i, node1))
    {
        return true;
    }
    return false;
}

/******************************************************************************************
 * class_name
 *     CLASS_NAME 
 *     template_id 
 ******************************************************************************************/

bool cpp_parser_class_name(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case CLASS_NAME:
        if(cpp_parser_shift_token<CLASS_NAME>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case TEMPLATE_NAME:
        if(cpp_parser_template_id(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * enum_name
 *     ENUM_NAME 
 ******************************************************************************************/

bool cpp_parser_enum_name(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<ENUM_NAME>(tokens, token_i, node1))
    {
        return true;
    }
    return false;
}

/******************************************************************************************
 * template_name
 *     TEMPLATE_NAME 
 ******************************************************************************************/

bool cpp_parser_template_name(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<TEMPLATE_NAME>(tokens, token_i, node1))
    {
        return true;
    }
    return false;
}

/******************************************************************************************
 * identifier
 *     IDENTIFIER 
 ******************************************************************************************/

bool cpp_parser_identifier(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<IDENTIFIER>(tokens, token_i, node1))
    {
        return true;
    }
    return false;
}

/******************************************************************************************
 * literal
 *     integer_literal 
 *     character_literal 
 *     floating_literal 
 *     string_literal 
 *     boolean_literal 
 ******************************************************************************************/

bool cpp_parser_literal(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case FALSE:
    case TRUE:
        if(cpp_parser_boolean_literal(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case CHARACTER:
        if(cpp_parser_character_literal(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case FLOATING:
        if(cpp_parser_floating_literal(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case INTEGER:
        if(cpp_parser_integer_literal(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case STRING:
        if(cpp_parser_string_literal(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * integer_literal
 *     INTEGER 
 ******************************************************************************************/

bool cpp_parser_integer_literal(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<INTEGER>(tokens, token_i, node1))
    {
        return true;
    }
    return false;
}

/******************************************************************************************
 * character_literal
 *     CHARACTER 
 ******************************************************************************************/

bool cpp_parser_character_literal(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<CHARACTER>(tokens, token_i, node1))
    {
        return true;
    }
    return false;
}

/******************************************************************************************
 * floating_literal
 *     FLOATING 
 ******************************************************************************************/

bool cpp_parser_floating_literal(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<FLOATING>(tokens, token_i, node1))
    {
        return true;
    }
    return false;
}

/******************************************************************************************
 * string_literal
 *     STRING 
 ******************************************************************************************/

bool cpp_parser_string_literal(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<STRING>(tokens, token_i, node1))
    {
        return true;
    }
    return false;
}

/******************************************************************************************
 * boolean_literal
 *     TRUE 
 *     FALSE 
 ******************************************************************************************/

bool cpp_parser_boolean_literal(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case FALSE:
        if(cpp_parser_shift_token<FALSE>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case TRUE:
        if(cpp_parser_shift_token<TRUE>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * translation_unit
 *     declaration_seq_opt 
 ******************************************************************************************/

bool cpp_parser_translation_unit(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_declaration_seq_opt(tokens, token_i, node1))
    {
        return true;
    }
    return false;
}

/******************************************************************************************
 * primary_expression
 *     literal 
 *     THIS 
 *     COLONCOLON identifier 
 *     COLONCOLON operator_function_id 
 *     COLONCOLON qualified_id 
 *     '(' expression ')' 
 *     id_expression 
 ******************************************************************************************/

bool cpp_parser_primary_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '(':
        if(cpp_parser_shift_token<'('>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_expression(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<')'>(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case COLONCOLON:
        if(cpp_parser_shift_token<COLONCOLON>(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case IDENTIFIER:
                if(cpp_parser_identifier(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            case OPERATOR:
                if(cpp_parser_operator_function_id(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            case CLASS_NAME:
            case NAMESPACE_NAME:
            case TEMPLATE_NAME:
                if(cpp_parser_qualified_id(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    case THIS:
        if(cpp_parser_shift_token<THIS>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '~':
    case CLASS_NAME:
    case IDENTIFIER:
    case NAMESPACE_NAME:
    case OPERATOR:
    case TEMPLATE_NAME:
        if(cpp_parser_id_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case CHARACTER:
    case FALSE:
    case FLOATING:
    case INTEGER:
    case STRING:
    case TRUE:
        if(cpp_parser_literal(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * id_expression
 *     unqualified_id 
 *     qualified_id 
 ******************************************************************************************/

bool cpp_parser_id_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case CLASS_NAME:
    case NAMESPACE_NAME:
    case TEMPLATE_NAME:
        if(cpp_parser_qualified_id(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_unqualified_id(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '~':
    case IDENTIFIER:
    case OPERATOR:
        if(cpp_parser_unqualified_id(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * unqualified_id
 *     identifier 
 *     operator_function_id 
 *     conversion_function_id 
 *     '~' class_name 
 *     template_id 
 ******************************************************************************************/

bool cpp_parser_unqualified_id(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '~':
        if(cpp_parser_shift_token<'~'>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_class_name(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    case OPERATOR:
        if(cpp_parser_conversion_function_id(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_operator_function_id(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case IDENTIFIER:
        if(cpp_parser_identifier(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case TEMPLATE_NAME:
        if(cpp_parser_template_id(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * qualified_id
 *     nested_name_specifier TEMPLATE_opt unqualified_id 
 ******************************************************************************************/

bool cpp_parser_qualified_id(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_nested_name_specifier(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_TEMPLATE_opt(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_unqualified_id(tokens, token_i, node3))
            {
                return true;
            }
        }
    }
    return false;
}

/******************************************************************************************
 * nested_name_specifier
 *     class_or_namespace_name COLONCOLON nested_name_specifier_opt 
 ******************************************************************************************/

bool cpp_parser_nested_name_specifier(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_class_or_namespace_name(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<COLONCOLON>(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_nested_name_specifier_opt(tokens, token_i, node3))
            {
                return true;
            }
        }
    }
    return false;
}

/******************************************************************************************
 * class_or_namespace_name
 *     class_name 
 *     namespace_name 
 ******************************************************************************************/

bool cpp_parser_class_or_namespace_name(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case CLASS_NAME:
    case TEMPLATE_NAME:
        if(cpp_parser_class_name(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case NAMESPACE_NAME:
        if(cpp_parser_namespace_name(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * postfix_expression
 *     primary_expression 
 *     postfix_expression '[' expression ']' 
 *     postfix_expression '(' expression_list_opt ')' 
 *     simple_type_specifier '(' expression_list_opt ')' 
 *     postfix_expression '.' TEMPLATE_opt COLONCOLON_opt id_expression 
 *     postfix_expression ARROW TEMPLATE_opt COLONCOLON_opt id_expression 
 *     postfix_expression '.' pseudo_destructor_name 
 *     postfix_expression ARROW pseudo_destructor_name 
 *     postfix_expression PLUSPLUS 
 *     postfix_expression MINUSMINUS 
 *     DYNAMIC_CAST '<' type_id '>' '(' expression ')' 
 *     STATIC_CAST '<' type_id '>' '(' expression ')' 
 *     REINTERPRET_CAST '<' type_id '>' '(' expression ')' 
 *     CONST_CAST '<' type_id '>' '(' expression ')' 
 *     TYPEID '(' expression ')' 
 *     TYPEID '(' type_id ')' 
 ******************************************************************************************/

bool cpp_parser_postfix_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case CONST_CAST:
        if(cpp_parser_shift_token<CONST_CAST>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'<'>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_type_id(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_shift_token<'>'>(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_shift_token<'('>(tokens, token_i, node5))
                        {
                            node_t node6;
                            if(cpp_parser_expression(tokens, token_i, node6))
                            {
                                node_t node7;
                                if(cpp_parser_shift_token<')'>(tokens, token_i, node7))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }

        token_i = current_i;
        if(cpp_parser_postfix_expression(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '(':
                if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_expression_list_opt(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            case '.':
                if(cpp_parser_shift_token<'.'>(tokens, token_i, node2))
                {
                    node_t node3;
                    int current_i = token_i;
                    switch(GET_TOKEN_ID(tokens, token_i))
                    {
                    case '~':
                    case CLASS_NAME:
                    case COLONCOLON:
                    case IDENTIFIER:
                    case NAMESPACE_NAME:
                    case OPERATOR:
                    case TEMPLATE:
                    case TEMPLATE_NAME:
                        if(cpp_parser_TEMPLATE_opt(tokens, token_i, node3))
                        {
                            node_t node4;
                            if(cpp_parser_COLONCOLON_opt(tokens, token_i, node4))
                            {
                                node_t node5;
                                if(cpp_parser_id_expression(tokens, token_i, node5))
                                {
                                    return true;
                                }
                            }
                        }

                        token_i = current_i;
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    case ENUM_NAME:
                    case TYPEDEF_NAME:
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    default:
                        REPORT_SWITCH_ERROR(tokens, token_i);
                    }
                }
                break;

            case '[':
                if(cpp_parser_shift_token<'['>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_expression(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<']'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            case ARROW:
                if(cpp_parser_shift_token<ARROW>(tokens, token_i, node2))
                {
                    node_t node3;
                    int current_i = token_i;
                    switch(GET_TOKEN_ID(tokens, token_i))
                    {
                    case '~':
                    case CLASS_NAME:
                    case COLONCOLON:
                    case IDENTIFIER:
                    case NAMESPACE_NAME:
                    case OPERATOR:
                    case TEMPLATE:
                    case TEMPLATE_NAME:
                        if(cpp_parser_TEMPLATE_opt(tokens, token_i, node3))
                        {
                            node_t node4;
                            if(cpp_parser_COLONCOLON_opt(tokens, token_i, node4))
                            {
                                node_t node5;
                                if(cpp_parser_id_expression(tokens, token_i, node5))
                                {
                                    return true;
                                }
                            }
                        }

                        token_i = current_i;
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    case ENUM_NAME:
                    case TYPEDEF_NAME:
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    default:
                        REPORT_SWITCH_ERROR(tokens, token_i);
                    }
                }
                break;

            case MINUSMINUS:
                if(cpp_parser_shift_token<MINUSMINUS>(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            case PLUSPLUS:
                if(cpp_parser_shift_token<PLUSPLUS>(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    case DYNAMIC_CAST:
        if(cpp_parser_shift_token<DYNAMIC_CAST>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'<'>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_type_id(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_shift_token<'>'>(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_shift_token<'('>(tokens, token_i, node5))
                        {
                            node_t node6;
                            if(cpp_parser_expression(tokens, token_i, node6))
                            {
                                node_t node7;
                                if(cpp_parser_shift_token<')'>(tokens, token_i, node7))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }

        token_i = current_i;
        if(cpp_parser_postfix_expression(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '(':
                if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_expression_list_opt(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            case '.':
                if(cpp_parser_shift_token<'.'>(tokens, token_i, node2))
                {
                    node_t node3;
                    int current_i = token_i;
                    switch(GET_TOKEN_ID(tokens, token_i))
                    {
                    case '~':
                    case CLASS_NAME:
                    case COLONCOLON:
                    case IDENTIFIER:
                    case NAMESPACE_NAME:
                    case OPERATOR:
                    case TEMPLATE:
                    case TEMPLATE_NAME:
                        if(cpp_parser_TEMPLATE_opt(tokens, token_i, node3))
                        {
                            node_t node4;
                            if(cpp_parser_COLONCOLON_opt(tokens, token_i, node4))
                            {
                                node_t node5;
                                if(cpp_parser_id_expression(tokens, token_i, node5))
                                {
                                    return true;
                                }
                            }
                        }

                        token_i = current_i;
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    case ENUM_NAME:
                    case TYPEDEF_NAME:
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    default:
                        REPORT_SWITCH_ERROR(tokens, token_i);
                    }
                }
                break;

            case '[':
                if(cpp_parser_shift_token<'['>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_expression(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<']'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            case ARROW:
                if(cpp_parser_shift_token<ARROW>(tokens, token_i, node2))
                {
                    node_t node3;
                    int current_i = token_i;
                    switch(GET_TOKEN_ID(tokens, token_i))
                    {
                    case '~':
                    case CLASS_NAME:
                    case COLONCOLON:
                    case IDENTIFIER:
                    case NAMESPACE_NAME:
                    case OPERATOR:
                    case TEMPLATE:
                    case TEMPLATE_NAME:
                        if(cpp_parser_TEMPLATE_opt(tokens, token_i, node3))
                        {
                            node_t node4;
                            if(cpp_parser_COLONCOLON_opt(tokens, token_i, node4))
                            {
                                node_t node5;
                                if(cpp_parser_id_expression(tokens, token_i, node5))
                                {
                                    return true;
                                }
                            }
                        }

                        token_i = current_i;
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    case ENUM_NAME:
                    case TYPEDEF_NAME:
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    default:
                        REPORT_SWITCH_ERROR(tokens, token_i);
                    }
                }
                break;

            case MINUSMINUS:
                if(cpp_parser_shift_token<MINUSMINUS>(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            case PLUSPLUS:
                if(cpp_parser_shift_token<PLUSPLUS>(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    case REINTERPRET_CAST:
        if(cpp_parser_shift_token<REINTERPRET_CAST>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'<'>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_type_id(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_shift_token<'>'>(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_shift_token<'('>(tokens, token_i, node5))
                        {
                            node_t node6;
                            if(cpp_parser_expression(tokens, token_i, node6))
                            {
                                node_t node7;
                                if(cpp_parser_shift_token<')'>(tokens, token_i, node7))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }

        token_i = current_i;
        if(cpp_parser_postfix_expression(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '(':
                if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_expression_list_opt(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            case '.':
                if(cpp_parser_shift_token<'.'>(tokens, token_i, node2))
                {
                    node_t node3;
                    int current_i = token_i;
                    switch(GET_TOKEN_ID(tokens, token_i))
                    {
                    case '~':
                    case CLASS_NAME:
                    case COLONCOLON:
                    case IDENTIFIER:
                    case NAMESPACE_NAME:
                    case OPERATOR:
                    case TEMPLATE:
                    case TEMPLATE_NAME:
                        if(cpp_parser_TEMPLATE_opt(tokens, token_i, node3))
                        {
                            node_t node4;
                            if(cpp_parser_COLONCOLON_opt(tokens, token_i, node4))
                            {
                                node_t node5;
                                if(cpp_parser_id_expression(tokens, token_i, node5))
                                {
                                    return true;
                                }
                            }
                        }

                        token_i = current_i;
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    case ENUM_NAME:
                    case TYPEDEF_NAME:
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    default:
                        REPORT_SWITCH_ERROR(tokens, token_i);
                    }
                }
                break;

            case '[':
                if(cpp_parser_shift_token<'['>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_expression(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<']'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            case ARROW:
                if(cpp_parser_shift_token<ARROW>(tokens, token_i, node2))
                {
                    node_t node3;
                    int current_i = token_i;
                    switch(GET_TOKEN_ID(tokens, token_i))
                    {
                    case '~':
                    case CLASS_NAME:
                    case COLONCOLON:
                    case IDENTIFIER:
                    case NAMESPACE_NAME:
                    case OPERATOR:
                    case TEMPLATE:
                    case TEMPLATE_NAME:
                        if(cpp_parser_TEMPLATE_opt(tokens, token_i, node3))
                        {
                            node_t node4;
                            if(cpp_parser_COLONCOLON_opt(tokens, token_i, node4))
                            {
                                node_t node5;
                                if(cpp_parser_id_expression(tokens, token_i, node5))
                                {
                                    return true;
                                }
                            }
                        }

                        token_i = current_i;
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    case ENUM_NAME:
                    case TYPEDEF_NAME:
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    default:
                        REPORT_SWITCH_ERROR(tokens, token_i);
                    }
                }
                break;

            case MINUSMINUS:
                if(cpp_parser_shift_token<MINUSMINUS>(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            case PLUSPLUS:
                if(cpp_parser_shift_token<PLUSPLUS>(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    case STATIC_CAST:
        if(cpp_parser_shift_token<STATIC_CAST>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'<'>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_type_id(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_shift_token<'>'>(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_shift_token<'('>(tokens, token_i, node5))
                        {
                            node_t node6;
                            if(cpp_parser_expression(tokens, token_i, node6))
                            {
                                node_t node7;
                                if(cpp_parser_shift_token<')'>(tokens, token_i, node7))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }

        token_i = current_i;
        if(cpp_parser_postfix_expression(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '(':
                if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_expression_list_opt(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            case '.':
                if(cpp_parser_shift_token<'.'>(tokens, token_i, node2))
                {
                    node_t node3;
                    int current_i = token_i;
                    switch(GET_TOKEN_ID(tokens, token_i))
                    {
                    case '~':
                    case CLASS_NAME:
                    case COLONCOLON:
                    case IDENTIFIER:
                    case NAMESPACE_NAME:
                    case OPERATOR:
                    case TEMPLATE:
                    case TEMPLATE_NAME:
                        if(cpp_parser_TEMPLATE_opt(tokens, token_i, node3))
                        {
                            node_t node4;
                            if(cpp_parser_COLONCOLON_opt(tokens, token_i, node4))
                            {
                                node_t node5;
                                if(cpp_parser_id_expression(tokens, token_i, node5))
                                {
                                    return true;
                                }
                            }
                        }

                        token_i = current_i;
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    case ENUM_NAME:
                    case TYPEDEF_NAME:
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    default:
                        REPORT_SWITCH_ERROR(tokens, token_i);
                    }
                }
                break;

            case '[':
                if(cpp_parser_shift_token<'['>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_expression(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<']'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            case ARROW:
                if(cpp_parser_shift_token<ARROW>(tokens, token_i, node2))
                {
                    node_t node3;
                    int current_i = token_i;
                    switch(GET_TOKEN_ID(tokens, token_i))
                    {
                    case '~':
                    case CLASS_NAME:
                    case COLONCOLON:
                    case IDENTIFIER:
                    case NAMESPACE_NAME:
                    case OPERATOR:
                    case TEMPLATE:
                    case TEMPLATE_NAME:
                        if(cpp_parser_TEMPLATE_opt(tokens, token_i, node3))
                        {
                            node_t node4;
                            if(cpp_parser_COLONCOLON_opt(tokens, token_i, node4))
                            {
                                node_t node5;
                                if(cpp_parser_id_expression(tokens, token_i, node5))
                                {
                                    return true;
                                }
                            }
                        }

                        token_i = current_i;
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    case ENUM_NAME:
                    case TYPEDEF_NAME:
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    default:
                        REPORT_SWITCH_ERROR(tokens, token_i);
                    }
                }
                break;

            case MINUSMINUS:
                if(cpp_parser_shift_token<MINUSMINUS>(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            case PLUSPLUS:
                if(cpp_parser_shift_token<PLUSPLUS>(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    case TYPEID:
        if(cpp_parser_shift_token<TYPEID>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
            {
                node_t node3;
                int current_i = token_i;
                switch(GET_TOKEN_ID(tokens, token_i))
                {
                case '!':
                case '%':
                case '&':
                case '(':
                case '*':
                case '+':
                case ',':
                case '-':
                case '.':
                case '/':
                case '<':
                case '=':
                case '>':
                case '[':
                case '^':
                case '|':
                case '~':
                case ADDEQ:
                case ANDAND:
                case ANDEQ:
                case ARROW:
                case ARROWSTAR:
                case BOOL:
                case CHAR:
                case CHARACTER:
                case CLASS_NAME:
                case COLONCOLON:
                case CONST_CAST:
                case DELETE:
                case DIVEQ:
                case DOTSTAR:
                case DOUBLE:
                case DYNAMIC_CAST:
                case ENUM_NAME:
                case EQ:
                case FALSE:
                case FLOAT:
                case FLOATING:
                case GTEQ:
                case IDENTIFIER:
                case INT:
                case INTEGER:
                case LONG:
                case LTEQ:
                case MINUSMINUS:
                case MODEQ:
                case MULEQ:
                case NAMESPACE_NAME:
                case NEW:
                case NOTEQ:
                case OPERATOR:
                case OREQ:
                case OROR:
                case PLUSPLUS:
                case REINTERPRET_CAST:
                case SHORT:
                case SIGNED:
                case SIZEOF:
                case SL:
                case SLEQ:
                case SR:
                case SREQ:
                case STATIC_CAST:
                case STRING:
                case SUBEQ:
                case TEMPLATE_NAME:
                case THIS:
                case THROW:
                case TRUE:
                case TYPEDEF_NAME:
                case TYPEID:
                case UNSIGNED:
                case VOID:
                case WCHAR_T:
                case XOREQ:
                    if(cpp_parser_expression(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }

                    token_i = current_i;
                    if(cpp_parser_type_id(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                    break;

                case CLASS:
                case CONST:
                case ENUM:
                case STRUCT:
                case TYPENAME:
                case UNION:
                case VOLATILE:
                    if(cpp_parser_type_id(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                    break;

                default:
                    REPORT_SWITCH_ERROR(tokens, token_i);
                }
            }
        }

        token_i = current_i;
        if(cpp_parser_postfix_expression(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '(':
                if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_expression_list_opt(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            case '.':
                if(cpp_parser_shift_token<'.'>(tokens, token_i, node2))
                {
                    node_t node3;
                    int current_i = token_i;
                    switch(GET_TOKEN_ID(tokens, token_i))
                    {
                    case '~':
                    case CLASS_NAME:
                    case COLONCOLON:
                    case IDENTIFIER:
                    case NAMESPACE_NAME:
                    case OPERATOR:
                    case TEMPLATE:
                    case TEMPLATE_NAME:
                        if(cpp_parser_TEMPLATE_opt(tokens, token_i, node3))
                        {
                            node_t node4;
                            if(cpp_parser_COLONCOLON_opt(tokens, token_i, node4))
                            {
                                node_t node5;
                                if(cpp_parser_id_expression(tokens, token_i, node5))
                                {
                                    return true;
                                }
                            }
                        }

                        token_i = current_i;
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    case ENUM_NAME:
                    case TYPEDEF_NAME:
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    default:
                        REPORT_SWITCH_ERROR(tokens, token_i);
                    }
                }
                break;

            case '[':
                if(cpp_parser_shift_token<'['>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_expression(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<']'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            case ARROW:
                if(cpp_parser_shift_token<ARROW>(tokens, token_i, node2))
                {
                    node_t node3;
                    int current_i = token_i;
                    switch(GET_TOKEN_ID(tokens, token_i))
                    {
                    case '~':
                    case CLASS_NAME:
                    case COLONCOLON:
                    case IDENTIFIER:
                    case NAMESPACE_NAME:
                    case OPERATOR:
                    case TEMPLATE:
                    case TEMPLATE_NAME:
                        if(cpp_parser_TEMPLATE_opt(tokens, token_i, node3))
                        {
                            node_t node4;
                            if(cpp_parser_COLONCOLON_opt(tokens, token_i, node4))
                            {
                                node_t node5;
                                if(cpp_parser_id_expression(tokens, token_i, node5))
                                {
                                    return true;
                                }
                            }
                        }

                        token_i = current_i;
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    case ENUM_NAME:
                    case TYPEDEF_NAME:
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    default:
                        REPORT_SWITCH_ERROR(tokens, token_i);
                    }
                }
                break;

            case MINUSMINUS:
                if(cpp_parser_shift_token<MINUSMINUS>(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            case PLUSPLUS:
                if(cpp_parser_shift_token<PLUSPLUS>(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    case '(':
    case '.':
    case '[':
    case '~':
    case ARROW:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case DOUBLE:
    case ENUM_NAME:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case MINUSMINUS:
    case NAMESPACE_NAME:
    case OPERATOR:
    case PLUSPLUS:
    case SHORT:
    case SIGNED:
    case STRING:
    case TEMPLATE_NAME:
    case THIS:
    case TRUE:
    case TYPEDEF_NAME:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_postfix_expression(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '(':
                if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_expression_list_opt(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            case '.':
                if(cpp_parser_shift_token<'.'>(tokens, token_i, node2))
                {
                    node_t node3;
                    int current_i = token_i;
                    switch(GET_TOKEN_ID(tokens, token_i))
                    {
                    case '~':
                    case CLASS_NAME:
                    case COLONCOLON:
                    case IDENTIFIER:
                    case NAMESPACE_NAME:
                    case OPERATOR:
                    case TEMPLATE:
                    case TEMPLATE_NAME:
                        if(cpp_parser_TEMPLATE_opt(tokens, token_i, node3))
                        {
                            node_t node4;
                            if(cpp_parser_COLONCOLON_opt(tokens, token_i, node4))
                            {
                                node_t node5;
                                if(cpp_parser_id_expression(tokens, token_i, node5))
                                {
                                    return true;
                                }
                            }
                        }

                        token_i = current_i;
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    case ENUM_NAME:
                    case TYPEDEF_NAME:
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    default:
                        REPORT_SWITCH_ERROR(tokens, token_i);
                    }
                }
                break;

            case '[':
                if(cpp_parser_shift_token<'['>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_expression(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<']'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            case ARROW:
                if(cpp_parser_shift_token<ARROW>(tokens, token_i, node2))
                {
                    node_t node3;
                    int current_i = token_i;
                    switch(GET_TOKEN_ID(tokens, token_i))
                    {
                    case '~':
                    case CLASS_NAME:
                    case COLONCOLON:
                    case IDENTIFIER:
                    case NAMESPACE_NAME:
                    case OPERATOR:
                    case TEMPLATE:
                    case TEMPLATE_NAME:
                        if(cpp_parser_TEMPLATE_opt(tokens, token_i, node3))
                        {
                            node_t node4;
                            if(cpp_parser_COLONCOLON_opt(tokens, token_i, node4))
                            {
                                node_t node5;
                                if(cpp_parser_id_expression(tokens, token_i, node5))
                                {
                                    return true;
                                }
                            }
                        }

                        token_i = current_i;
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    case ENUM_NAME:
                    case TYPEDEF_NAME:
                        if(cpp_parser_pseudo_destructor_name(tokens, token_i, node3))
                        {
                            return true;
                        }
                        break;

                    default:
                        REPORT_SWITCH_ERROR(tokens, token_i);
                    }
                }
                break;

            case MINUSMINUS:
                if(cpp_parser_shift_token<MINUSMINUS>(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            case PLUSPLUS:
                if(cpp_parser_shift_token<PLUSPLUS>(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }

        token_i = current_i;
        if(cpp_parser_primary_expression(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_simple_type_specifier(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_expression_list_opt(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                    {
                        return true;
                    }
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * expression_list
 *     assignment_expression 
 *     expression_list ',' assignment_expression 
 ******************************************************************************************/

bool cpp_parser_expression_list(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '=':
    case '>':
    case '[':
    case '^':
    case '|':
    case '~':
    case ADDEQ:
    case ANDAND:
    case ANDEQ:
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DIVEQ:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case MODEQ:
    case MULEQ:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case OREQ:
    case OROR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SLEQ:
    case SR:
    case SREQ:
    case STATIC_CAST:
    case STRING:
    case SUBEQ:
    case TEMPLATE_NAME:
    case THIS:
    case THROW:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
    case XOREQ:
        if(cpp_parser_assignment_expression(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_expression_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_assignment_expression(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case ',':
        if(cpp_parser_expression_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_assignment_expression(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * pseudo_destructor_name
 *     COLONCOLON_opt nested_name_specifier_opt type_name COLONCOLON '~' type_name 
 *     COLONCOLON_opt nested_name_specifier_opt '~' type_name 
 ******************************************************************************************/

bool cpp_parser_pseudo_destructor_name(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_COLONCOLON_opt(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_nested_name_specifier_opt(tokens, token_i, node2))
        {
            node_t node3;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '~':
                if(cpp_parser_shift_token<'~'>(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_type_name(tokens, token_i, node4))
                    {
                        return true;
                    }
                }
                break;

            case CLASS_NAME:
            case ENUM_NAME:
            case TEMPLATE_NAME:
            case TYPEDEF_NAME:
                if(cpp_parser_type_name(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_shift_token<COLONCOLON>(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_shift_token<'~'>(tokens, token_i, node5))
                        {
                            node_t node6;
                            if(cpp_parser_type_name(tokens, token_i, node6))
                            {
                                return true;
                            }
                        }
                    }
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
    }
    return false;
}

/******************************************************************************************
 * unary_expression
 *     postfix_expression 
 *     PLUSPLUS cast_expression 
 *     MINUSMINUS cast_expression 
 *     unary_operator cast_expression 
 *     SIZEOF unary_expression 
 *     SIZEOF '(' type_id ')' 
 *     new_expression 
 *     delete_expression 
 ******************************************************************************************/

bool cpp_parser_unary_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case MINUSMINUS:
        if(cpp_parser_shift_token<MINUSMINUS>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_cast_expression(tokens, token_i, node2))
            {
                return true;
            }
        }

        token_i = current_i;
        if(cpp_parser_postfix_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case PLUSPLUS:
        if(cpp_parser_shift_token<PLUSPLUS>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_cast_expression(tokens, token_i, node2))
            {
                return true;
            }
        }

        token_i = current_i;
        if(cpp_parser_postfix_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case SIZEOF:
        if(cpp_parser_shift_token<SIZEOF>(tokens, token_i, node1))
        {
            node_t node2;
            int current_i = token_i;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '(':
                if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_type_id(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }

                token_i = current_i;
                if(cpp_parser_unary_expression(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            case '!':
            case '&':
            case '*':
            case '+':
            case '-':
            case '.':
            case '[':
            case '~':
            case ARROW:
            case BOOL:
            case CHAR:
            case CHARACTER:
            case CLASS_NAME:
            case COLONCOLON:
            case CONST_CAST:
            case DELETE:
            case DOUBLE:
            case DYNAMIC_CAST:
            case ENUM_NAME:
            case FALSE:
            case FLOAT:
            case FLOATING:
            case IDENTIFIER:
            case INT:
            case INTEGER:
            case LONG:
            case MINUSMINUS:
            case NAMESPACE_NAME:
            case NEW:
            case OPERATOR:
            case PLUSPLUS:
            case REINTERPRET_CAST:
            case SHORT:
            case SIGNED:
            case SIZEOF:
            case STATIC_CAST:
            case STRING:
            case TEMPLATE_NAME:
            case THIS:
            case TRUE:
            case TYPEDEF_NAME:
            case TYPEID:
            case UNSIGNED:
            case VOID:
            case WCHAR_T:
                if(cpp_parser_unary_expression(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    case COLONCOLON:
    case DELETE:
        if(cpp_parser_delete_expression(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_new_expression(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_postfix_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case NEW:
        if(cpp_parser_new_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '(':
    case '.':
    case '[':
    case '~':
    case ARROW:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case CONST_CAST:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case NAMESPACE_NAME:
    case OPERATOR:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case STATIC_CAST:
    case STRING:
    case TEMPLATE_NAME:
    case THIS:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_postfix_expression(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_unary_operator(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_cast_expression(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    case '!':
    case '&':
    case '*':
    case '+':
    case '-':
        if(cpp_parser_unary_operator(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_cast_expression(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * unary_operator
 *     '*' 
 *     '&' 
 *     '+' 
 *     '-' 
 *     '!' 
 *     '~' 
 ******************************************************************************************/

bool cpp_parser_unary_operator(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
        if(cpp_parser_shift_token<'!'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '&':
        if(cpp_parser_shift_token<'&'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '*':
        if(cpp_parser_shift_token<'*'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '+':
        if(cpp_parser_shift_token<'+'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '-':
        if(cpp_parser_shift_token<'-'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '~':
        if(cpp_parser_shift_token<'~'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * new_expression
 *     COLONCOLON_opt NEW new_placement_opt new_type_id new_initializer_opt 
 *     COLONCOLON_opt NEW new_placement_opt '(' type_id ')' new_initializer_opt 
 ******************************************************************************************/

bool cpp_parser_new_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_COLONCOLON_opt(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<NEW>(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_new_placement_opt(tokens, token_i, node3))
            {
                node_t node4;
                switch(GET_TOKEN_ID(tokens, token_i))
                {
                case '(':
                    if(cpp_parser_shift_token<'('>(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_type_id(tokens, token_i, node5))
                        {
                            node_t node6;
                            if(cpp_parser_shift_token<')'>(tokens, token_i, node6))
                            {
                                node_t node7;
                                if(cpp_parser_new_initializer_opt(tokens, token_i, node7))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                    break;

                case BOOL:
                case CHAR:
                case CLASS:
                case CLASS_NAME:
                case COLONCOLON:
                case CONST:
                case DOUBLE:
                case ENUM:
                case ENUM_NAME:
                case FLOAT:
                case IDENTIFIER:
                case INT:
                case LONG:
                case NAMESPACE_NAME:
                case SHORT:
                case SIGNED:
                case STRUCT:
                case TEMPLATE_NAME:
                case TYPEDEF_NAME:
                case TYPENAME:
                case UNION:
                case UNSIGNED:
                case VOID:
                case VOLATILE:
                case WCHAR_T:
                    if(cpp_parser_new_type_id(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_new_initializer_opt(tokens, token_i, node5))
                        {
                            return true;
                        }
                    }
                    break;

                default:
                    REPORT_SWITCH_ERROR(tokens, token_i);
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * new_placement
 *     '(' expression_list ')' 
 ******************************************************************************************/

bool cpp_parser_new_placement(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<'('>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_expression_list(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_shift_token<')'>(tokens, token_i, node3))
            {
                return true;
            }
        }
    }
    return false;
}

/******************************************************************************************
 * new_type_id
 *     type_specifier_seq new_declarator_opt 
 ******************************************************************************************/

bool cpp_parser_new_type_id(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_type_specifier_seq(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_new_declarator_opt(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * new_declarator
 *     ptr_operator new_declarator_opt 
 *     direct_new_declarator 
 ******************************************************************************************/

bool cpp_parser_new_declarator(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '[':
        if(cpp_parser_direct_new_declarator(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '&':
    case '*':
    case CLASS_NAME:
    case COLONCOLON:
    case NAMESPACE_NAME:
    case TEMPLATE_NAME:
        if(cpp_parser_ptr_operator(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_new_declarator_opt(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * direct_new_declarator
 *     '[' expression ']' 
 *     direct_new_declarator '[' constant_expression ']' 
 ******************************************************************************************/

bool cpp_parser_direct_new_declarator(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '[':
        if(cpp_parser_shift_token<'['>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_expression(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<']'>(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }

        token_i = current_i;
        if(cpp_parser_direct_new_declarator(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'['>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_constant_expression(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_shift_token<']'>(tokens, token_i, node4))
                    {
                        return true;
                    }
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * new_initializer
 *     '(' expression_list_opt ')' 
 ******************************************************************************************/

bool cpp_parser_new_initializer(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<'('>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_expression_list_opt(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_shift_token<')'>(tokens, token_i, node3))
            {
                return true;
            }
        }
    }
    return false;
}

/******************************************************************************************
 * delete_expression
 *     COLONCOLON_opt DELETE cast_expression 
 *     COLONCOLON_opt DELETE '[' ']' cast_expression 
 ******************************************************************************************/

bool cpp_parser_delete_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_COLONCOLON_opt(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<DELETE>(tokens, token_i, node2))
        {
            node_t node3;
            int current_i = token_i;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '[':
                if(cpp_parser_shift_token<'['>(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_shift_token<']'>(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_cast_expression(tokens, token_i, node5))
                        {
                            return true;
                        }
                    }
                }

                token_i = current_i;
                if(cpp_parser_cast_expression(tokens, token_i, node3))
                {
                    return true;
                }
                break;

            case '!':
            case '&':
            case '(':
            case '*':
            case '+':
            case '-':
            case '.':
            case '~':
            case ARROW:
            case BOOL:
            case CHAR:
            case CHARACTER:
            case CLASS_NAME:
            case COLONCOLON:
            case CONST_CAST:
            case DELETE:
            case DOUBLE:
            case DYNAMIC_CAST:
            case ENUM_NAME:
            case FALSE:
            case FLOAT:
            case FLOATING:
            case IDENTIFIER:
            case INT:
            case INTEGER:
            case LONG:
            case MINUSMINUS:
            case NAMESPACE_NAME:
            case NEW:
            case OPERATOR:
            case PLUSPLUS:
            case REINTERPRET_CAST:
            case SHORT:
            case SIGNED:
            case SIZEOF:
            case STATIC_CAST:
            case STRING:
            case TEMPLATE_NAME:
            case THIS:
            case TRUE:
            case TYPEDEF_NAME:
            case TYPEID:
            case UNSIGNED:
            case VOID:
            case WCHAR_T:
                if(cpp_parser_cast_expression(tokens, token_i, node3))
                {
                    return true;
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
    }
    return false;
}

/******************************************************************************************
 * cast_expression
 *     unary_expression 
 *     '(' type_id ')' cast_expression 
 ******************************************************************************************/

bool cpp_parser_cast_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '(':
        if(cpp_parser_shift_token<'('>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_type_id(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<')'>(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_cast_expression(tokens, token_i, node4))
                    {
                        return true;
                    }
                }
            }
        }

        token_i = current_i;
        if(cpp_parser_unary_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '!':
    case '&':
    case '*':
    case '+':
    case '-':
    case '.':
    case '[':
    case '~':
    case ARROW:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case MINUSMINUS:
    case NAMESPACE_NAME:
    case NEW:
    case OPERATOR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case STATIC_CAST:
    case STRING:
    case TEMPLATE_NAME:
    case THIS:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_unary_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * pm_expression
 *     cast_expression 
 *     pm_expression DOTSTAR cast_expression 
 *     pm_expression ARROWSTAR cast_expression 
 ******************************************************************************************/

bool cpp_parser_pm_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '[':
    case '~':
    case ARROW:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case MINUSMINUS:
    case NAMESPACE_NAME:
    case NEW:
    case OPERATOR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case STATIC_CAST:
    case STRING:
    case TEMPLATE_NAME:
    case THIS:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_cast_expression(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_pm_expression(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case ARROWSTAR:
                if(cpp_parser_shift_token<ARROWSTAR>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_cast_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            case DOTSTAR:
                if(cpp_parser_shift_token<DOTSTAR>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_cast_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    case ARROWSTAR:
    case DOTSTAR:
        if(cpp_parser_pm_expression(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case ARROWSTAR:
                if(cpp_parser_shift_token<ARROWSTAR>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_cast_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            case DOTSTAR:
                if(cpp_parser_shift_token<DOTSTAR>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_cast_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * multiplicative_expression
 *     pm_expression 
 *     multiplicative_expression '*' pm_expression 
 *     multiplicative_expression '/' pm_expression 
 *     multiplicative_expression '%' pm_expression 
 ******************************************************************************************/

bool cpp_parser_multiplicative_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '[':
    case '~':
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case MINUSMINUS:
    case NAMESPACE_NAME:
    case NEW:
    case OPERATOR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case STATIC_CAST:
    case STRING:
    case TEMPLATE_NAME:
    case THIS:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_multiplicative_expression(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '%':
                if(cpp_parser_shift_token<'%'>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_pm_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            case '*':
                if(cpp_parser_shift_token<'*'>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_pm_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            case '/':
                if(cpp_parser_shift_token<'/'>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_pm_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }

        token_i = current_i;
        if(cpp_parser_pm_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * additive_expression
 *     multiplicative_expression 
 *     additive_expression '+' multiplicative_expression 
 *     additive_expression '-' multiplicative_expression 
 ******************************************************************************************/

bool cpp_parser_additive_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '[':
    case '~':
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case MINUSMINUS:
    case NAMESPACE_NAME:
    case NEW:
    case OPERATOR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case STATIC_CAST:
    case STRING:
    case TEMPLATE_NAME:
    case THIS:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_additive_expression(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '+':
                if(cpp_parser_shift_token<'+'>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_multiplicative_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            case '-':
                if(cpp_parser_shift_token<'-'>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_multiplicative_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }

        token_i = current_i;
        if(cpp_parser_multiplicative_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * shift_expression
 *     additive_expression 
 *     shift_expression SL additive_expression 
 *     shift_expression SR additive_expression 
 ******************************************************************************************/

bool cpp_parser_shift_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '[':
    case '~':
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case MINUSMINUS:
    case NAMESPACE_NAME:
    case NEW:
    case OPERATOR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case STATIC_CAST:
    case STRING:
    case TEMPLATE_NAME:
    case THIS:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_additive_expression(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_shift_expression(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case SL:
                if(cpp_parser_shift_token<SL>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_additive_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            case SR:
                if(cpp_parser_shift_token<SR>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_additive_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    case SL:
    case SR:
        if(cpp_parser_shift_expression(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case SL:
                if(cpp_parser_shift_token<SL>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_additive_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            case SR:
                if(cpp_parser_shift_token<SR>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_additive_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * relational_expression
 *     shift_expression 
 *     relational_expression '<' shift_expression 
 *     relational_expression '>' shift_expression 
 *     relational_expression LTEQ shift_expression 
 *     relational_expression GTEQ shift_expression 
 ******************************************************************************************/

bool cpp_parser_relational_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '>':
    case '[':
    case '~':
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case NAMESPACE_NAME:
    case NEW:
    case OPERATOR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SR:
    case STATIC_CAST:
    case STRING:
    case TEMPLATE_NAME:
    case THIS:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_relational_expression(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '<':
                if(cpp_parser_shift_token<'<'>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_shift_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            case '>':
                if(cpp_parser_shift_token<'>'>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_shift_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            case GTEQ:
                if(cpp_parser_shift_token<GTEQ>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_shift_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            case LTEQ:
                if(cpp_parser_shift_token<LTEQ>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_shift_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }

        token_i = current_i;
        if(cpp_parser_shift_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * equality_expression
 *     relational_expression 
 *     equality_expression EQ relational_expression 
 *     equality_expression NOTEQ relational_expression 
 ******************************************************************************************/

bool cpp_parser_equality_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '>':
    case '[':
    case '~':
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SR:
    case STATIC_CAST:
    case STRING:
    case TEMPLATE_NAME:
    case THIS:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_equality_expression(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case EQ:
                if(cpp_parser_shift_token<EQ>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_relational_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            case NOTEQ:
                if(cpp_parser_shift_token<NOTEQ>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_relational_expression(tokens, token_i, node3))
                    {
                        return true;
                    }
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }

        token_i = current_i;
        if(cpp_parser_relational_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * and_expression
 *     equality_expression 
 *     and_expression '&' equality_expression 
 ******************************************************************************************/

bool cpp_parser_and_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '>':
    case '[':
    case '~':
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SR:
    case STATIC_CAST:
    case STRING:
    case TEMPLATE_NAME:
    case THIS:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_and_expression(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'&'>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_equality_expression(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }

        token_i = current_i;
        if(cpp_parser_equality_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * exclusive_or_expression
 *     and_expression 
 *     exclusive_or_expression '^' and_expression 
 ******************************************************************************************/

bool cpp_parser_exclusive_or_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '>':
    case '[':
    case '~':
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SR:
    case STATIC_CAST:
    case STRING:
    case TEMPLATE_NAME:
    case THIS:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_and_expression(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_exclusive_or_expression(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'^'>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_and_expression(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case '^':
        if(cpp_parser_exclusive_or_expression(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'^'>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_and_expression(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * inclusive_or_expression
 *     exclusive_or_expression 
 *     inclusive_or_expression '|' exclusive_or_expression 
 ******************************************************************************************/

bool cpp_parser_inclusive_or_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '>':
    case '[':
    case '^':
    case '~':
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SR:
    case STATIC_CAST:
    case STRING:
    case TEMPLATE_NAME:
    case THIS:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_exclusive_or_expression(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_inclusive_or_expression(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'|'>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_exclusive_or_expression(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case '|':
        if(cpp_parser_inclusive_or_expression(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'|'>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_exclusive_or_expression(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * logical_and_expression
 *     inclusive_or_expression 
 *     logical_and_expression ANDAND inclusive_or_expression 
 ******************************************************************************************/

bool cpp_parser_logical_and_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '>':
    case '[':
    case '^':
    case '|':
    case '~':
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SR:
    case STATIC_CAST:
    case STRING:
    case TEMPLATE_NAME:
    case THIS:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_inclusive_or_expression(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_logical_and_expression(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<ANDAND>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_inclusive_or_expression(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case ANDAND:
        if(cpp_parser_logical_and_expression(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<ANDAND>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_inclusive_or_expression(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * logical_or_expression
 *     logical_and_expression 
 *     logical_or_expression OROR logical_and_expression 
 ******************************************************************************************/

bool cpp_parser_logical_or_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '>':
    case '[':
    case '^':
    case '|':
    case '~':
    case ANDAND:
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SR:
    case STATIC_CAST:
    case STRING:
    case TEMPLATE_NAME:
    case THIS:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_logical_and_expression(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_logical_or_expression(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<OROR>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_logical_and_expression(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case OROR:
        if(cpp_parser_logical_or_expression(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<OROR>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_logical_and_expression(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * conditional_expression
 *     logical_or_expression 
 *     logical_or_expression '?' expression ':' assignment_expression 
 ******************************************************************************************/

bool cpp_parser_conditional_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_logical_or_expression(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<'?'>(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_expression(tokens, token_i, node3))
            {
                node_t node4;
                if(cpp_parser_shift_token<':'>(tokens, token_i, node4))
                {
                    node_t node5;
                    if(cpp_parser_assignment_expression(tokens, token_i, node5))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * assignment_expression
 *     conditional_expression 
 *     logical_or_expression assignment_operator assignment_expression 
 *     throw_expression 
 ******************************************************************************************/

bool cpp_parser_assignment_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '>':
    case '[':
    case '^':
    case '|':
    case '~':
    case ANDAND:
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case OROR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SR:
    case STATIC_CAST:
    case STRING:
    case TEMPLATE_NAME:
    case THIS:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_conditional_expression(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_logical_or_expression(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_assignment_operator(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_assignment_expression(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case THROW:
        if(cpp_parser_throw_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * assignment_operator
 *     '=' 
 *     MULEQ 
 *     DIVEQ 
 *     MODEQ 
 *     ADDEQ 
 *     SUBEQ 
 *     SREQ 
 *     SLEQ 
 *     ANDEQ 
 *     XOREQ 
 *     OREQ 
 ******************************************************************************************/

bool cpp_parser_assignment_operator(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '=':
        if(cpp_parser_shift_token<'='>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ADDEQ:
        if(cpp_parser_shift_token<ADDEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ANDEQ:
        if(cpp_parser_shift_token<ANDEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case DIVEQ:
        if(cpp_parser_shift_token<DIVEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case MODEQ:
        if(cpp_parser_shift_token<MODEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case MULEQ:
        if(cpp_parser_shift_token<MULEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case OREQ:
        if(cpp_parser_shift_token<OREQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case SLEQ:
        if(cpp_parser_shift_token<SLEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case SREQ:
        if(cpp_parser_shift_token<SREQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case SUBEQ:
        if(cpp_parser_shift_token<SUBEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case XOREQ:
        if(cpp_parser_shift_token<XOREQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * expression
 *     assignment_expression 
 *     expression ',' assignment_expression 
 ******************************************************************************************/

bool cpp_parser_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '=':
    case '>':
    case '[':
    case '^':
    case '|':
    case '~':
    case ADDEQ:
    case ANDAND:
    case ANDEQ:
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DIVEQ:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case MODEQ:
    case MULEQ:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case OREQ:
    case OROR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SLEQ:
    case SR:
    case SREQ:
    case STATIC_CAST:
    case STRING:
    case SUBEQ:
    case TEMPLATE_NAME:
    case THIS:
    case THROW:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
    case XOREQ:
        if(cpp_parser_assignment_expression(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_expression(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_assignment_expression(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case ',':
        if(cpp_parser_expression(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_assignment_expression(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * constant_expression
 *     conditional_expression 
 ******************************************************************************************/

bool cpp_parser_constant_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_conditional_expression(tokens, token_i, node1))
    {
        return true;
    }
    return false;
}

/******************************************************************************************
 * statement
 *     labeled_statement 
 *     expression_statement 
 *     compound_statement 
 *     selection_statement 
 *     iteration_statement 
 *     jump_statement 
 *     declaration_statement 
 *     try_block 
 ******************************************************************************************/

bool cpp_parser_statement(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '{':
        if(cpp_parser_compound_statement(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '&':
    case '(':
    case '*':
    case ',':
    case ';':
    case '[':
    case '~':
    case ASM:
    case AUTO:
    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case EXPLICIT:
    case EXTERN:
    case FLOAT:
    case FRIEND:
    case IDENTIFIER:
    case INLINE:
    case INT:
    case LONG:
    case MUTABLE:
    case NAMESPACE:
    case NAMESPACE_NAME:
    case OPERATOR:
    case REGISTER:
    case SHORT:
    case SIGNED:
    case STATIC:
    case STRUCT:
    case TEMPLATE:
    case TEMPLATE_NAME:
    case TYPEDEF:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case USING:
    case VIRTUAL:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_declaration_statement(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_expression_statement(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_labeled_statement(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '!':
    case '%':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '=':
    case '>':
    case '^':
    case '|':
    case ADDEQ:
    case ANDAND:
    case ANDEQ:
    case ARROW:
    case ARROWSTAR:
    case CHARACTER:
    case CONST_CAST:
    case DELETE:
    case DIVEQ:
    case DOTSTAR:
    case DYNAMIC_CAST:
    case EQ:
    case FALSE:
    case FLOATING:
    case GTEQ:
    case INTEGER:
    case LTEQ:
    case MINUSMINUS:
    case MODEQ:
    case MULEQ:
    case NEW:
    case NOTEQ:
    case OREQ:
    case OROR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SIZEOF:
    case SL:
    case SLEQ:
    case SR:
    case SREQ:
    case STATIC_CAST:
    case STRING:
    case SUBEQ:
    case THIS:
    case THROW:
    case TRUE:
    case TYPEID:
    case XOREQ:
        if(cpp_parser_expression_statement(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case DO:
    case FOR:
    case WHILE:
        if(cpp_parser_iteration_statement(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case BREAK:
    case CONTINUE:
    case GOTO:
    case RETURN:
        if(cpp_parser_jump_statement(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case CASE:
    case DEFAULT:
        if(cpp_parser_labeled_statement(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case IF:
    case SWITCH:
        if(cpp_parser_selection_statement(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case TRY:
        if(cpp_parser_try_block(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * labeled_statement
 *     identifier ':' statement 
 *     CASE constant_expression ':' statement 
 *     DEFAULT ':' statement 
 ******************************************************************************************/

bool cpp_parser_labeled_statement(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case CASE:
        if(cpp_parser_shift_token<CASE>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_constant_expression(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<':'>(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_statement(tokens, token_i, node4))
                    {
                        return true;
                    }
                }
            }
        }
        break;

    case DEFAULT:
        if(cpp_parser_shift_token<DEFAULT>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<':'>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_statement(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case IDENTIFIER:
        if(cpp_parser_identifier(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<':'>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_statement(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * expression_statement
 *     expression_opt ';' 
 ******************************************************************************************/

bool cpp_parser_expression_statement(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_expression_opt(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<';'>(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * compound_statement
 *     '{' statement_seq_opt '}' 
 ******************************************************************************************/

bool cpp_parser_compound_statement(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<'{'>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_statement_seq_opt(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_shift_token<'}'>(tokens, token_i, node3))
            {
                return true;
            }
        }
    }
    return false;
}

/******************************************************************************************
 * statement_seq
 *     statement 
 *     statement_seq statement 
 ******************************************************************************************/

bool cpp_parser_statement_seq(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case ',':
    case '-':
    case '.':
    case '/':
    case ':':
    case ';':
    case '<':
    case '=':
    case '>':
    case '[':
    case '^':
    case '{':
    case '|':
    case '~':
    case ADDEQ:
    case ANDAND:
    case ANDEQ:
    case ARROW:
    case ARROWSTAR:
    case ASM:
    case AUTO:
    case BOOL:
    case BREAK:
    case CASE:
    case CHAR:
    case CHARACTER:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case CONST_CAST:
    case CONTINUE:
    case DEFAULT:
    case DELETE:
    case DIVEQ:
    case DO:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM:
    case ENUM_NAME:
    case EQ:
    case EXPLICIT:
    case EXTERN:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case FOR:
    case FRIEND:
    case GOTO:
    case GTEQ:
    case IDENTIFIER:
    case IF:
    case INLINE:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case MODEQ:
    case MULEQ:
    case MUTABLE:
    case NAMESPACE:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case OREQ:
    case OROR:
    case PLUSPLUS:
    case REGISTER:
    case REINTERPRET_CAST:
    case RETURN:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SLEQ:
    case SR:
    case SREQ:
    case STATIC:
    case STATIC_CAST:
    case STRING:
    case STRUCT:
    case SUBEQ:
    case SWITCH:
    case TEMPLATE:
    case TEMPLATE_NAME:
    case THIS:
    case THROW:
    case TRUE:
    case TRY:
    case TYPEDEF:
    case TYPEDEF_NAME:
    case TYPEID:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case USING:
    case VIRTUAL:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
    case WHILE:
    case XOREQ:
        if(cpp_parser_statement(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_statement_seq(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_statement(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * selection_statement
 *     IF '(' condition ')' statement 
 *     IF '(' condition ')' statement ELSE statement 
 *     SWITCH '(' condition ')' statement 
 ******************************************************************************************/

bool cpp_parser_selection_statement(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case IF:
        if(cpp_parser_shift_token<IF>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_condition(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_statement(tokens, token_i, node5))
                        {
                            node_t node6;
                            if(cpp_parser_shift_token<ELSE>(tokens, token_i, node6))
                            {
                                node_t node7;
                                if(cpp_parser_statement(tokens, token_i, node7))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;

    case SWITCH:
        if(cpp_parser_shift_token<SWITCH>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_condition(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_statement(tokens, token_i, node5))
                        {
                            return true;
                        }
                    }
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * condition
 *     expression 
 *     type_specifier_seq declarator '=' assignment_expression 
 ******************************************************************************************/

bool cpp_parser_condition(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case ',':
    case '-':
    case '.':
    case '/':
    case '<':
    case '=':
    case '>':
    case '[':
    case '^':
    case '|':
    case '~':
    case ADDEQ:
    case ANDAND:
    case ANDEQ:
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DIVEQ:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case MODEQ:
    case MULEQ:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case OREQ:
    case OROR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SLEQ:
    case SR:
    case SREQ:
    case STATIC_CAST:
    case STRING:
    case SUBEQ:
    case TEMPLATE_NAME:
    case THIS:
    case THROW:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
    case XOREQ:
        if(cpp_parser_expression(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_type_specifier_seq(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_declarator(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<'='>(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_assignment_expression(tokens, token_i, node4))
                    {
                        return true;
                    }
                }
            }
        }
        break;

    case CLASS:
    case CONST:
    case ENUM:
    case STRUCT:
    case TYPENAME:
    case UNION:
    case VOLATILE:
        if(cpp_parser_type_specifier_seq(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_declarator(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<'='>(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_assignment_expression(tokens, token_i, node4))
                    {
                        return true;
                    }
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * iteration_statement
 *     WHILE '(' condition ')' statement 
 *     DO statement WHILE '(' expression ')' ';' 
 *     FOR '(' for_init_statement condition_opt ';' expression_opt ')' statement 
 ******************************************************************************************/

bool cpp_parser_iteration_statement(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case DO:
        if(cpp_parser_shift_token<DO>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_statement(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<WHILE>(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_shift_token<'('>(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_expression(tokens, token_i, node5))
                        {
                            node_t node6;
                            if(cpp_parser_shift_token<')'>(tokens, token_i, node6))
                            {
                                node_t node7;
                                if(cpp_parser_shift_token<';'>(tokens, token_i, node7))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;

    case FOR:
        if(cpp_parser_shift_token<FOR>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_for_init_statement(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_condition_opt(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_shift_token<';'>(tokens, token_i, node5))
                        {
                            node_t node6;
                            if(cpp_parser_expression_opt(tokens, token_i, node6))
                            {
                                node_t node7;
                                if(cpp_parser_shift_token<')'>(tokens, token_i, node7))
                                {
                                    node_t node8;
                                    if(cpp_parser_statement(tokens, token_i, node8))
                                    {
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        break;

    case WHILE:
        if(cpp_parser_shift_token<WHILE>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_condition(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_statement(tokens, token_i, node5))
                        {
                            return true;
                        }
                    }
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * for_init_statement
 *     expression_statement 
 *     simple_declaration 
 ******************************************************************************************/

bool cpp_parser_for_init_statement(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case ',':
    case '-':
    case '.':
    case '/':
    case ';':
    case '<':
    case '=':
    case '>':
    case '[':
    case '^':
    case '|':
    case '~':
    case ADDEQ:
    case ANDAND:
    case ANDEQ:
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DIVEQ:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case MODEQ:
    case MULEQ:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case OREQ:
    case OROR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SLEQ:
    case SR:
    case SREQ:
    case STATIC_CAST:
    case STRING:
    case SUBEQ:
    case TEMPLATE_NAME:
    case THIS:
    case THROW:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
    case XOREQ:
        if(cpp_parser_expression_statement(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_simple_declaration(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case AUTO:
    case CLASS:
    case CONST:
    case ENUM:
    case EXPLICIT:
    case EXTERN:
    case FRIEND:
    case INLINE:
    case MUTABLE:
    case REGISTER:
    case STATIC:
    case STRUCT:
    case TEMPLATE:
    case TYPEDEF:
    case TYPENAME:
    case UNION:
    case VIRTUAL:
    case VOLATILE:
        if(cpp_parser_simple_declaration(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * jump_statement
 *     BREAK ';' 
 *     CONTINUE ';' 
 *     RETURN expression_opt ';' 
 *     GOTO identifier ';' 
 ******************************************************************************************/

bool cpp_parser_jump_statement(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case BREAK:
        if(cpp_parser_shift_token<BREAK>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<';'>(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    case CONTINUE:
        if(cpp_parser_shift_token<CONTINUE>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<';'>(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    case GOTO:
        if(cpp_parser_shift_token<GOTO>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_identifier(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<';'>(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case RETURN:
        if(cpp_parser_shift_token<RETURN>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_expression_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<';'>(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * declaration_statement
 *     block_declaration 
 ******************************************************************************************/

bool cpp_parser_declaration_statement(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_block_declaration(tokens, token_i, node1))
    {
        return true;
    }
    return false;
}

/******************************************************************************************
 * declaration_seq
 *     declaration 
 *     declaration_seq declaration 
 ******************************************************************************************/

bool cpp_parser_declaration_seq(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '&':
    case '(':
    case '*':
    case ',':
    case ':':
    case ';':
    case '[':
    case '{':
    case '~':
    case ASM:
    case AUTO:
    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case EXPLICIT:
    case EXPORT:
    case EXTERN:
    case FLOAT:
    case FRIEND:
    case IDENTIFIER:
    case INLINE:
    case INT:
    case LONG:
    case MUTABLE:
    case NAMESPACE:
    case NAMESPACE_NAME:
    case OPERATOR:
    case REGISTER:
    case SHORT:
    case SIGNED:
    case STATIC:
    case STRUCT:
    case TEMPLATE:
    case TEMPLATE_NAME:
    case TRY:
    case TYPEDEF:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case USING:
    case VIRTUAL:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_declaration(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_declaration_seq(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_declaration(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * declaration
 *     block_declaration 
 *     function_definition 
 *     template_declaration 
 *     explicit_instantiation 
 *     explicit_specialization 
 *     linkage_specification 
 *     namespace_definition 
 ******************************************************************************************/

bool cpp_parser_declaration(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '&':
    case '(':
    case '*':
    case ',':
    case ';':
    case '[':
    case '~':
    case ASM:
    case AUTO:
    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case EXPLICIT:
    case EXTERN:
    case FLOAT:
    case FRIEND:
    case IDENTIFIER:
    case INLINE:
    case INT:
    case LONG:
    case MUTABLE:
    case NAMESPACE:
    case NAMESPACE_NAME:
    case OPERATOR:
    case REGISTER:
    case SHORT:
    case SIGNED:
    case STATIC:
    case STRUCT:
    case TEMPLATE:
    case TEMPLATE_NAME:
    case TYPEDEF:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case USING:
    case VIRTUAL:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_block_declaration(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_explicit_instantiation(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_explicit_specialization(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_function_definition(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_linkage_specification(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_namespace_definition(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_template_declaration(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case EXPORT:
        if(cpp_parser_template_declaration(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * block_declaration
 *     simple_declaration 
 *     asm_definition 
 *     namespace_alias_definition 
 *     using_declaration 
 *     using_directive 
 ******************************************************************************************/

bool cpp_parser_block_declaration(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case ASM:
        if(cpp_parser_asm_definition(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case NAMESPACE:
        if(cpp_parser_namespace_alias_definition(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '&':
    case '(':
    case '*':
    case ',':
    case ';':
    case '[':
    case '~':
    case AUTO:
    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case EXPLICIT:
    case EXTERN:
    case FLOAT:
    case FRIEND:
    case IDENTIFIER:
    case INLINE:
    case INT:
    case LONG:
    case MUTABLE:
    case NAMESPACE_NAME:
    case OPERATOR:
    case REGISTER:
    case SHORT:
    case SIGNED:
    case STATIC:
    case STRUCT:
    case TEMPLATE:
    case TEMPLATE_NAME:
    case TYPEDEF:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case VIRTUAL:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_simple_declaration(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case USING:
        if(cpp_parser_using_declaration(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_using_directive(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * simple_declaration
 *     decl_specifier_seq_opt init_declarator_list_opt ';' 
 ******************************************************************************************/

bool cpp_parser_simple_declaration(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_decl_specifier_seq_opt(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_init_declarator_list_opt(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_shift_token<';'>(tokens, token_i, node3))
            {
                return true;
            }
        }
    }
    return false;
}

/******************************************************************************************
 * decl_specifier
 *     storage_class_specifier 
 *     type_specifier 
 *     function_specifier 
 *     FRIEND 
 *     TYPEDEF 
 ******************************************************************************************/

bool cpp_parser_decl_specifier(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case FRIEND:
        if(cpp_parser_shift_token<FRIEND>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case TYPEDEF:
        if(cpp_parser_shift_token<TYPEDEF>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case EXPLICIT:
    case INLINE:
    case VIRTUAL:
        if(cpp_parser_function_specifier(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case AUTO:
    case EXTERN:
    case MUTABLE:
    case REGISTER:
    case STATIC:
        if(cpp_parser_storage_class_specifier(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case FLOAT:
    case IDENTIFIER:
    case INT:
    case LONG:
    case NAMESPACE_NAME:
    case SHORT:
    case SIGNED:
    case STRUCT:
    case TEMPLATE_NAME:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_type_specifier(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * decl_specifier_seq
 *     decl_specifier_seq_opt decl_specifier 
 ******************************************************************************************/

bool cpp_parser_decl_specifier_seq(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_decl_specifier_seq_opt(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_decl_specifier(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * storage_class_specifier
 *     AUTO 
 *     REGISTER 
 *     STATIC 
 *     EXTERN 
 *     MUTABLE 
 ******************************************************************************************/

bool cpp_parser_storage_class_specifier(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case AUTO:
        if(cpp_parser_shift_token<AUTO>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case EXTERN:
        if(cpp_parser_shift_token<EXTERN>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case MUTABLE:
        if(cpp_parser_shift_token<MUTABLE>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case REGISTER:
        if(cpp_parser_shift_token<REGISTER>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case STATIC:
        if(cpp_parser_shift_token<STATIC>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * function_specifier
 *     INLINE 
 *     VIRTUAL 
 *     EXPLICIT 
 ******************************************************************************************/

bool cpp_parser_function_specifier(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case EXPLICIT:
        if(cpp_parser_shift_token<EXPLICIT>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case INLINE:
        if(cpp_parser_shift_token<INLINE>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case VIRTUAL:
        if(cpp_parser_shift_token<VIRTUAL>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * type_specifier
 *     simple_type_specifier 
 *     class_specifier 
 *     enum_specifier 
 *     elaborated_type_specifier 
 *     cv_qualifier 
 ******************************************************************************************/

bool cpp_parser_type_specifier(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case CLASS:
    case STRUCT:
    case UNION:
        if(cpp_parser_class_specifier(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_elaborated_type_specifier(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case CONST:
    case VOLATILE:
        if(cpp_parser_cv_qualifier(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ENUM:
    case TYPENAME:
        if(cpp_parser_elaborated_type_specifier(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_enum_specifier(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case BOOL:
    case CHAR:
    case CLASS_NAME:
    case COLONCOLON:
    case DOUBLE:
    case ENUM_NAME:
    case FLOAT:
    case INT:
    case LONG:
    case NAMESPACE_NAME:
    case SHORT:
    case SIGNED:
    case TEMPLATE_NAME:
    case TYPEDEF_NAME:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_simple_type_specifier(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * simple_type_specifier
 *     COLONCOLON_opt nested_name_specifier_opt type_name 
 *     CHAR 
 *     WCHAR_T 
 *     BOOL 
 *     SHORT 
 *     INT 
 *     LONG 
 *     SIGNED 
 *     UNSIGNED 
 *     FLOAT 
 *     DOUBLE 
 *     VOID 
 ******************************************************************************************/

bool cpp_parser_simple_type_specifier(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case BOOL:
        if(cpp_parser_shift_token<BOOL>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case CHAR:
        if(cpp_parser_shift_token<CHAR>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case CLASS_NAME:
    case COLONCOLON:
    case ENUM_NAME:
    case NAMESPACE_NAME:
    case TEMPLATE_NAME:
    case TYPEDEF_NAME:
        if(cpp_parser_COLONCOLON_opt(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_nested_name_specifier_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_type_name(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case DOUBLE:
        if(cpp_parser_shift_token<DOUBLE>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case FLOAT:
        if(cpp_parser_shift_token<FLOAT>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case INT:
        if(cpp_parser_shift_token<INT>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case LONG:
        if(cpp_parser_shift_token<LONG>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case SHORT:
        if(cpp_parser_shift_token<SHORT>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case SIGNED:
        if(cpp_parser_shift_token<SIGNED>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case UNSIGNED:
        if(cpp_parser_shift_token<UNSIGNED>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case VOID:
        if(cpp_parser_shift_token<VOID>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case WCHAR_T:
        if(cpp_parser_shift_token<WCHAR_T>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * type_name
 *     class_name 
 *     enum_name 
 *     typedef_name 
 ******************************************************************************************/

bool cpp_parser_type_name(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case CLASS_NAME:
    case TEMPLATE_NAME:
        if(cpp_parser_class_name(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ENUM_NAME:
        if(cpp_parser_enum_name(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case TYPEDEF_NAME:
        if(cpp_parser_typedef_name(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * elaborated_type_specifier
 *     class_key COLONCOLON_opt nested_name_specifier_opt identifier 
 *     ENUM COLONCOLON_opt nested_name_specifier_opt identifier 
 *     TYPENAME COLONCOLON_opt nested_name_specifier identifier 
 *     TYPENAME COLONCOLON_opt nested_name_specifier identifier '<' template_argument_list '>' 
 ******************************************************************************************/

bool cpp_parser_elaborated_type_specifier(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case ENUM:
        if(cpp_parser_shift_token<ENUM>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_COLONCOLON_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_nested_name_specifier_opt(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_identifier(tokens, token_i, node4))
                    {
                        return true;
                    }
                }
            }
        }
        break;

    case TYPENAME:
        if(cpp_parser_shift_token<TYPENAME>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_COLONCOLON_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_nested_name_specifier(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_identifier(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_shift_token<'<'>(tokens, token_i, node5))
                        {
                            node_t node6;
                            if(cpp_parser_template_argument_list(tokens, token_i, node6))
                            {
                                node_t node7;
                                if(cpp_parser_shift_token<'>'>(tokens, token_i, node7))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;

    case CLASS:
    case STRUCT:
    case UNION:
        if(cpp_parser_class_key(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_COLONCOLON_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_nested_name_specifier_opt(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_identifier(tokens, token_i, node4))
                    {
                        return true;
                    }
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * enum_specifier
 *     ENUM identifier_opt '{' enumerator_list_opt '}' 
 ******************************************************************************************/

bool cpp_parser_enum_specifier(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<ENUM>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_identifier_opt(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_shift_token<'{'>(tokens, token_i, node3))
            {
                node_t node4;
                if(cpp_parser_enumerator_list_opt(tokens, token_i, node4))
                {
                    node_t node5;
                    if(cpp_parser_shift_token<'}'>(tokens, token_i, node5))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * enumerator_list
 *     enumerator_definition 
 *     enumerator_list ',' enumerator_definition 
 ******************************************************************************************/

bool cpp_parser_enumerator_list(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case IDENTIFIER:
        if(cpp_parser_enumerator_definition(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_enumerator_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_enumerator_definition(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case ',':
        if(cpp_parser_enumerator_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_enumerator_definition(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * enumerator_definition
 *     enumerator 
 *     enumerator '=' constant_expression 
 ******************************************************************************************/

bool cpp_parser_enumerator_definition(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_enumerator(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<'='>(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_constant_expression(tokens, token_i, node3))
            {
                return true;
            }
        }
    }
    return false;
}

/******************************************************************************************
 * enumerator
 *     identifier 
 ******************************************************************************************/

bool cpp_parser_enumerator(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_identifier(tokens, token_i, node1))
    {
        return true;
    }
    return false;
}

/******************************************************************************************
 * namespace_definition
 *     named_namespace_definition 
 *     unnamed_namespace_definition 
 ******************************************************************************************/

bool cpp_parser_namespace_definition(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case NAMESPACE:
        if(cpp_parser_named_namespace_definition(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_unnamed_namespace_definition(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * named_namespace_definition
 *     original_namespace_definition 
 *     extension_namespace_definition 
 ******************************************************************************************/

bool cpp_parser_named_namespace_definition(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case NAMESPACE:
        if(cpp_parser_extension_namespace_definition(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_original_namespace_definition(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * original_namespace_definition
 *     NAMESPACE identifier '{' namespace_body '}' 
 ******************************************************************************************/

bool cpp_parser_original_namespace_definition(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<NAMESPACE>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_identifier(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_shift_token<'{'>(tokens, token_i, node3))
            {
                node_t node4;
                if(cpp_parser_namespace_body(tokens, token_i, node4))
                {
                    node_t node5;
                    if(cpp_parser_shift_token<'}'>(tokens, token_i, node5))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * extension_namespace_definition
 *     NAMESPACE original_namespace_name '{' namespace_body '}' 
 ******************************************************************************************/

bool cpp_parser_extension_namespace_definition(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<NAMESPACE>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_original_namespace_name(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_shift_token<'{'>(tokens, token_i, node3))
            {
                node_t node4;
                if(cpp_parser_namespace_body(tokens, token_i, node4))
                {
                    node_t node5;
                    if(cpp_parser_shift_token<'}'>(tokens, token_i, node5))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * unnamed_namespace_definition
 *     NAMESPACE '{' namespace_body '}' 
 ******************************************************************************************/

bool cpp_parser_unnamed_namespace_definition(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<NAMESPACE>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<'{'>(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_namespace_body(tokens, token_i, node3))
            {
                node_t node4;
                if(cpp_parser_shift_token<'}'>(tokens, token_i, node4))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * namespace_body
 *     declaration_seq_opt 
 ******************************************************************************************/

bool cpp_parser_namespace_body(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_declaration_seq_opt(tokens, token_i, node1))
    {
        return true;
    }
    return false;
}

/******************************************************************************************
 * namespace_alias_definition
 *     NAMESPACE identifier '=' qualified_namespace_specifier ';' 
 ******************************************************************************************/

bool cpp_parser_namespace_alias_definition(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<NAMESPACE>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_identifier(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_shift_token<'='>(tokens, token_i, node3))
            {
                node_t node4;
                if(cpp_parser_qualified_namespace_specifier(tokens, token_i, node4))
                {
                    node_t node5;
                    if(cpp_parser_shift_token<';'>(tokens, token_i, node5))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * qualified_namespace_specifier
 *     COLONCOLON_opt nested_name_specifier_opt namespace_name 
 ******************************************************************************************/

bool cpp_parser_qualified_namespace_specifier(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_COLONCOLON_opt(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_nested_name_specifier_opt(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_namespace_name(tokens, token_i, node3))
            {
                return true;
            }
        }
    }
    return false;
}

/******************************************************************************************
 * using_declaration
 *     USING TYPENAME_opt COLONCOLON_opt nested_name_specifier unqualified_id ';' 
 *     USING COLONCOLON unqualified_id ';' 
 ******************************************************************************************/

bool cpp_parser_using_declaration(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<USING>(tokens, token_i, node1))
    {
        node_t node2;
        int current_i = token_i;
        switch(GET_TOKEN_ID(tokens, token_i))
        {
        case COLONCOLON:
            if(cpp_parser_shift_token<COLONCOLON>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_unqualified_id(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_shift_token<';'>(tokens, token_i, node4))
                    {
                        return true;
                    }
                }
            }

            token_i = current_i;
            if(cpp_parser_TYPENAME_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_COLONCOLON_opt(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_nested_name_specifier(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_unqualified_id(tokens, token_i, node5))
                        {
                            node_t node6;
                            if(cpp_parser_shift_token<';'>(tokens, token_i, node6))
                            {
                                return true;
                            }
                        }
                    }
                }
            }
            break;

        case CLASS_NAME:
        case NAMESPACE_NAME:
        case TEMPLATE_NAME:
        case TYPENAME:
            if(cpp_parser_TYPENAME_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_COLONCOLON_opt(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_nested_name_specifier(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_unqualified_id(tokens, token_i, node5))
                        {
                            node_t node6;
                            if(cpp_parser_shift_token<';'>(tokens, token_i, node6))
                            {
                                return true;
                            }
                        }
                    }
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
 * using_directive
 *     USING NAMESPACE COLONCOLON_opt nested_name_specifier_opt namespace_name ';' 
 ******************************************************************************************/

bool cpp_parser_using_directive(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<USING>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<NAMESPACE>(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_COLONCOLON_opt(tokens, token_i, node3))
            {
                node_t node4;
                if(cpp_parser_nested_name_specifier_opt(tokens, token_i, node4))
                {
                    node_t node5;
                    if(cpp_parser_namespace_name(tokens, token_i, node5))
                    {
                        node_t node6;
                        if(cpp_parser_shift_token<';'>(tokens, token_i, node6))
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * asm_definition
 *     ASM '(' string_literal ')' ';' 
 ******************************************************************************************/

bool cpp_parser_asm_definition(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<ASM>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_string_literal(tokens, token_i, node3))
            {
                node_t node4;
                if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                {
                    node_t node5;
                    if(cpp_parser_shift_token<';'>(tokens, token_i, node5))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * linkage_specification
 *     EXTERN string_literal '{' declaration_seq_opt '}' 
 *     EXTERN string_literal declaration 
 ******************************************************************************************/

bool cpp_parser_linkage_specification(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<EXTERN>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_string_literal(tokens, token_i, node2))
        {
            node_t node3;
            int current_i = token_i;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '{':
                if(cpp_parser_shift_token<'{'>(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_declaration_seq_opt(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_shift_token<'}'>(tokens, token_i, node5))
                        {
                            return true;
                        }
                    }
                }

                token_i = current_i;
                if(cpp_parser_declaration(tokens, token_i, node3))
                {
                    return true;
                }
                break;

            case '&':
            case '(':
            case '*':
            case ',':
            case ':':
            case ';':
            case '[':
            case '~':
            case ASM:
            case AUTO:
            case BOOL:
            case CHAR:
            case CLASS:
            case CLASS_NAME:
            case COLONCOLON:
            case CONST:
            case DOUBLE:
            case ENUM:
            case ENUM_NAME:
            case EXPLICIT:
            case EXPORT:
            case EXTERN:
            case FLOAT:
            case FRIEND:
            case IDENTIFIER:
            case INLINE:
            case INT:
            case LONG:
            case MUTABLE:
            case NAMESPACE:
            case NAMESPACE_NAME:
            case OPERATOR:
            case REGISTER:
            case SHORT:
            case SIGNED:
            case STATIC:
            case STRUCT:
            case TEMPLATE:
            case TEMPLATE_NAME:
            case TRY:
            case TYPEDEF:
            case TYPEDEF_NAME:
            case TYPENAME:
            case UNION:
            case UNSIGNED:
            case USING:
            case VIRTUAL:
            case VOID:
            case VOLATILE:
            case WCHAR_T:
                if(cpp_parser_declaration(tokens, token_i, node3))
                {
                    return true;
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
    }
    return false;
}

/******************************************************************************************
 * init_declarator_list
 *     init_declarator 
 *     init_declarator_list ',' init_declarator 
 ******************************************************************************************/

bool cpp_parser_init_declarator_list(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '&':
    case '(':
    case '*':
    case '[':
    case '~':
    case CLASS_NAME:
    case COLONCOLON:
    case ENUM_NAME:
    case IDENTIFIER:
    case NAMESPACE_NAME:
    case OPERATOR:
    case TEMPLATE_NAME:
    case TYPEDEF_NAME:
        if(cpp_parser_init_declarator(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_init_declarator_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_init_declarator(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case ',':
        if(cpp_parser_init_declarator_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_init_declarator(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * init_declarator
 *     declarator initializer_opt 
 ******************************************************************************************/

bool cpp_parser_init_declarator(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_declarator(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_initializer_opt(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * declarator
 *     direct_declarator 
 *     ptr_operator declarator 
 ******************************************************************************************/

bool cpp_parser_declarator(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '(':
    case '[':
    case '~':
    case CLASS_NAME:
    case COLONCOLON:
    case ENUM_NAME:
    case IDENTIFIER:
    case NAMESPACE_NAME:
    case OPERATOR:
    case TEMPLATE_NAME:
    case TYPEDEF_NAME:
        if(cpp_parser_direct_declarator(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_ptr_operator(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_declarator(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    case '&':
    case '*':
        if(cpp_parser_ptr_operator(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_declarator(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * direct_declarator
 *     declarator_id 
 *     direct_declarator '(' parameter_declaration_clause ')' cv_qualifier_seq_opt exception_specification_opt 
 *     direct_declarator '[' constant_expression_opt ']' 
 *     '(' declarator ')' 
 ******************************************************************************************/

bool cpp_parser_direct_declarator(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '(':
        if(cpp_parser_shift_token<'('>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_declarator(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<')'>(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }

        token_i = current_i;
        if(cpp_parser_direct_declarator(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '(':
                if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_parameter_declaration_clause(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                        {
                            node_t node5;
                            if(cpp_parser_cv_qualifier_seq_opt(tokens, token_i, node5))
                            {
                                node_t node6;
                                if(cpp_parser_exception_specification_opt(tokens, token_i, node6))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
                break;

            case '[':
                if(cpp_parser_shift_token<'['>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_constant_expression_opt(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<']'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    case '~':
    case CLASS_NAME:
    case COLONCOLON:
    case ENUM_NAME:
    case IDENTIFIER:
    case NAMESPACE_NAME:
    case OPERATOR:
    case TEMPLATE_NAME:
    case TYPEDEF_NAME:
        if(cpp_parser_declarator_id(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_direct_declarator(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '(':
                if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_parameter_declaration_clause(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                        {
                            node_t node5;
                            if(cpp_parser_cv_qualifier_seq_opt(tokens, token_i, node5))
                            {
                                node_t node6;
                                if(cpp_parser_exception_specification_opt(tokens, token_i, node6))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
                break;

            case '[':
                if(cpp_parser_shift_token<'['>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_constant_expression_opt(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<']'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    case '[':
        if(cpp_parser_direct_declarator(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '(':
                if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_parameter_declaration_clause(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                        {
                            node_t node5;
                            if(cpp_parser_cv_qualifier_seq_opt(tokens, token_i, node5))
                            {
                                node_t node6;
                                if(cpp_parser_exception_specification_opt(tokens, token_i, node6))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
                break;

            case '[':
                if(cpp_parser_shift_token<'['>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_constant_expression_opt(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<']'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * ptr_operator
 *     '*' cv_qualifier_seq_opt 
 *     '&' 
 *     COLONCOLON_opt nested_name_specifier '*' cv_qualifier_seq_opt 
 ******************************************************************************************/

bool cpp_parser_ptr_operator(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '&':
        if(cpp_parser_shift_token<'&'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '*':
        if(cpp_parser_shift_token<'*'>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_cv_qualifier_seq_opt(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    case CLASS_NAME:
    case COLONCOLON:
    case NAMESPACE_NAME:
    case TEMPLATE_NAME:
        if(cpp_parser_COLONCOLON_opt(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_nested_name_specifier(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<'*'>(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_cv_qualifier_seq_opt(tokens, token_i, node4))
                    {
                        return true;
                    }
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * cv_qualifier_seq
 *     cv_qualifier cv_qualifier_seq_opt 
 ******************************************************************************************/

bool cpp_parser_cv_qualifier_seq(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_cv_qualifier(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_cv_qualifier_seq_opt(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * cv_qualifier
 *     CONST 
 *     VOLATILE 
 ******************************************************************************************/

bool cpp_parser_cv_qualifier(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case CONST:
        if(cpp_parser_shift_token<CONST>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case VOLATILE:
        if(cpp_parser_shift_token<VOLATILE>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * declarator_id
 *     COLONCOLON_opt id_expression 
 *     COLONCOLON_opt nested_name_specifier_opt type_name 
 ******************************************************************************************/

bool cpp_parser_declarator_id(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_COLONCOLON_opt(tokens, token_i, node1))
    {
        node_t node2;
        int current_i = token_i;
        switch(GET_TOKEN_ID(tokens, token_i))
        {
        case '~':
        case CLASS_NAME:
        case IDENTIFIER:
        case NAMESPACE_NAME:
        case OPERATOR:
        case TEMPLATE_NAME:
            if(cpp_parser_id_expression(tokens, token_i, node2))
            {
                return true;
            }

            token_i = current_i;
            if(cpp_parser_nested_name_specifier_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_type_name(tokens, token_i, node3))
                {
                    return true;
                }
            }
            break;

        case ENUM_NAME:
        case TYPEDEF_NAME:
            if(cpp_parser_nested_name_specifier_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_type_name(tokens, token_i, node3))
                {
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
 * type_id
 *     type_specifier_seq abstract_declarator_opt 
 ******************************************************************************************/

bool cpp_parser_type_id(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_type_specifier_seq(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_abstract_declarator_opt(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * type_specifier_seq
 *     type_specifier type_specifier_seq_opt 
 ******************************************************************************************/

bool cpp_parser_type_specifier_seq(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_type_specifier(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_type_specifier_seq_opt(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * abstract_declarator
 *     ptr_operator abstract_declarator_opt 
 *     direct_abstract_declarator 
 ******************************************************************************************/

bool cpp_parser_abstract_declarator(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '(':
    case '[':
        if(cpp_parser_direct_abstract_declarator(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '&':
    case '*':
    case CLASS_NAME:
    case COLONCOLON:
    case NAMESPACE_NAME:
    case TEMPLATE_NAME:
        if(cpp_parser_ptr_operator(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_abstract_declarator_opt(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * direct_abstract_declarator
 *     direct_abstract_declarator_opt '(' parameter_declaration_clause ')' cv_qualifier_seq_opt exception_specification_opt 
 *     direct_abstract_declarator_opt '[' constant_expression_opt ']' 
 *     '(' abstract_declarator ')' 
 ******************************************************************************************/

bool cpp_parser_direct_abstract_declarator(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '(':
        if(cpp_parser_shift_token<'('>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_abstract_declarator(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<')'>(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }

        token_i = current_i;
        if(cpp_parser_direct_abstract_declarator_opt(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '(':
                if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_parameter_declaration_clause(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                        {
                            node_t node5;
                            if(cpp_parser_cv_qualifier_seq_opt(tokens, token_i, node5))
                            {
                                node_t node6;
                                if(cpp_parser_exception_specification_opt(tokens, token_i, node6))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
                break;

            case '[':
                if(cpp_parser_shift_token<'['>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_constant_expression_opt(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<']'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    case '[':
        if(cpp_parser_direct_abstract_declarator_opt(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '(':
                if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_parameter_declaration_clause(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                        {
                            node_t node5;
                            if(cpp_parser_cv_qualifier_seq_opt(tokens, token_i, node5))
                            {
                                node_t node6;
                                if(cpp_parser_exception_specification_opt(tokens, token_i, node6))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
                break;

            case '[':
                if(cpp_parser_shift_token<'['>(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_constant_expression_opt(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<']'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * parameter_declaration_clause
 *     parameter_declaration_list_opt ELLIPSIS_opt 
 *     parameter_declaration_list ',' ELLIPSIS 
 ******************************************************************************************/

bool cpp_parser_parameter_declaration_clause(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case ',':
    case AUTO:
    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case EXPLICIT:
    case EXTERN:
    case FLOAT:
    case FRIEND:
    case IDENTIFIER:
    case INLINE:
    case INT:
    case LONG:
    case MUTABLE:
    case NAMESPACE_NAME:
    case REGISTER:
    case SHORT:
    case SIGNED:
    case STATIC:
    case STRUCT:
    case TEMPLATE_NAME:
    case TYPEDEF:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case VIRTUAL:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_parameter_declaration_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<ELLIPSIS>(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }

        token_i = current_i;
        if(cpp_parser_parameter_declaration_list_opt(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_ELLIPSIS_opt(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    case ELLIPSIS:
        if(cpp_parser_parameter_declaration_list_opt(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_ELLIPSIS_opt(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * parameter_declaration_list
 *     parameter_declaration 
 *     parameter_declaration_list ',' parameter_declaration 
 ******************************************************************************************/

bool cpp_parser_parameter_declaration_list(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case AUTO:
    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case EXPLICIT:
    case EXTERN:
    case FLOAT:
    case FRIEND:
    case IDENTIFIER:
    case INLINE:
    case INT:
    case LONG:
    case MUTABLE:
    case NAMESPACE_NAME:
    case REGISTER:
    case SHORT:
    case SIGNED:
    case STATIC:
    case STRUCT:
    case TEMPLATE_NAME:
    case TYPEDEF:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case VIRTUAL:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_parameter_declaration(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_parameter_declaration_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_parameter_declaration(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case ',':
        if(cpp_parser_parameter_declaration_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_parameter_declaration(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * parameter_declaration
 *     decl_specifier_seq declarator 
 *     decl_specifier_seq declarator '=' assignment_expression 
 *     decl_specifier_seq abstract_declarator_opt 
 *     decl_specifier_seq abstract_declarator_opt '=' assignment_expression 
 ******************************************************************************************/

bool cpp_parser_parameter_declaration(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_decl_specifier_seq(tokens, token_i, node1))
    {
        node_t node2;
        int current_i = token_i;
        switch(GET_TOKEN_ID(tokens, token_i))
        {
        case '&':
        case '(':
        case '*':
        case '=':
        case '[':
        case CLASS_NAME:
        case COLONCOLON:
        case NAMESPACE_NAME:
        case TEMPLATE_NAME:
            if(cpp_parser_abstract_declarator_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<'='>(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_assignment_expression(tokens, token_i, node4))
                    {
                        return true;
                    }
                }
            }

            token_i = current_i;
            if(cpp_parser_declarator(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<'='>(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_assignment_expression(tokens, token_i, node4))
                    {
                        return true;
                    }
                }
            }
            break;

        case '~':
        case ENUM_NAME:
        case IDENTIFIER:
        case OPERATOR:
        case TYPEDEF_NAME:
            if(cpp_parser_declarator(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<'='>(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_assignment_expression(tokens, token_i, node4))
                    {
                        return true;
                    }
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
 * function_definition
 *     decl_specifier_seq_opt declarator ctor_initializer_opt function_body 
 *     decl_specifier_seq_opt declarator function_try_block 
 ******************************************************************************************/

bool cpp_parser_function_definition(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_decl_specifier_seq_opt(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_declarator(tokens, token_i, node2))
        {
            node_t node3;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case ':':
            case '{':
                if(cpp_parser_ctor_initializer_opt(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_function_body(tokens, token_i, node4))
                    {
                        return true;
                    }
                }
                break;

            case TRY:
                if(cpp_parser_function_try_block(tokens, token_i, node3))
                {
                    return true;
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
    }
    return false;
}

/******************************************************************************************
 * function_body
 *     compound_statement 
 ******************************************************************************************/

bool cpp_parser_function_body(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_compound_statement(tokens, token_i, node1))
    {
        return true;
    }
    return false;
}

/******************************************************************************************
 * initializer
 *     '=' initializer_clause 
 *     '(' expression_list ')' 
 ******************************************************************************************/

bool cpp_parser_initializer(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '(':
        if(cpp_parser_shift_token<'('>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_expression_list(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<')'>(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case '=':
        if(cpp_parser_shift_token<'='>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_initializer_clause(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * initializer_clause
 *     assignment_expression 
 *     '{' initializer_list COMMA_opt '}' 
 *     '{' '}' 
 ******************************************************************************************/

bool cpp_parser_initializer_clause(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '{':
        if(cpp_parser_shift_token<'{'>(tokens, token_i, node1))
        {
            node_t node2;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '}':
                if(cpp_parser_shift_token<'}'>(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            case '!':
            case '%':
            case '&':
            case '(':
            case '*':
            case '+':
            case ',':
            case '-':
            case '.':
            case '/':
            case '<':
            case '=':
            case '>':
            case '[':
            case '^':
            case '{':
            case '|':
            case '~':
            case ADDEQ:
            case ANDAND:
            case ANDEQ:
            case ARROW:
            case ARROWSTAR:
            case BOOL:
            case CHAR:
            case CHARACTER:
            case CLASS_NAME:
            case COLONCOLON:
            case CONST_CAST:
            case DELETE:
            case DIVEQ:
            case DOTSTAR:
            case DOUBLE:
            case DYNAMIC_CAST:
            case ENUM_NAME:
            case EQ:
            case FALSE:
            case FLOAT:
            case FLOATING:
            case GTEQ:
            case IDENTIFIER:
            case INT:
            case INTEGER:
            case LONG:
            case LTEQ:
            case MINUSMINUS:
            case MODEQ:
            case MULEQ:
            case NAMESPACE_NAME:
            case NEW:
            case NOTEQ:
            case OPERATOR:
            case OREQ:
            case OROR:
            case PLUSPLUS:
            case REINTERPRET_CAST:
            case SHORT:
            case SIGNED:
            case SIZEOF:
            case SL:
            case SLEQ:
            case SR:
            case SREQ:
            case STATIC_CAST:
            case STRING:
            case SUBEQ:
            case TEMPLATE_NAME:
            case THIS:
            case THROW:
            case TRUE:
            case TYPEDEF_NAME:
            case TYPEID:
            case UNSIGNED:
            case VOID:
            case WCHAR_T:
            case XOREQ:
                if(cpp_parser_initializer_list(tokens, token_i, node2))
                {
                    node_t node3;
                    if(cpp_parser_COMMA_opt(tokens, token_i, node3))
                    {
                        node_t node4;
                        if(cpp_parser_shift_token<'}'>(tokens, token_i, node4))
                        {
                            return true;
                        }
                    }
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '=':
    case '>':
    case '[':
    case '^':
    case '|':
    case '~':
    case ADDEQ:
    case ANDAND:
    case ANDEQ:
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DIVEQ:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case MODEQ:
    case MULEQ:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case OREQ:
    case OROR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SLEQ:
    case SR:
    case SREQ:
    case STATIC_CAST:
    case STRING:
    case SUBEQ:
    case TEMPLATE_NAME:
    case THIS:
    case THROW:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
    case XOREQ:
        if(cpp_parser_assignment_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * initializer_list
 *     initializer_clause 
 *     initializer_list ',' initializer_clause 
 ******************************************************************************************/

bool cpp_parser_initializer_list(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '=':
    case '>':
    case '[':
    case '^':
    case '{':
    case '|':
    case '~':
    case ADDEQ:
    case ANDAND:
    case ANDEQ:
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DIVEQ:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case MODEQ:
    case MULEQ:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case OREQ:
    case OROR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SLEQ:
    case SR:
    case SREQ:
    case STATIC_CAST:
    case STRING:
    case SUBEQ:
    case TEMPLATE_NAME:
    case THIS:
    case THROW:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
    case XOREQ:
        if(cpp_parser_initializer_clause(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_initializer_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_initializer_clause(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case ',':
        if(cpp_parser_initializer_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_initializer_clause(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * class_specifier
 *     class_head '{' member_specification_opt '}' 
 ******************************************************************************************/

bool cpp_parser_class_specifier(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_class_head(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<'{'>(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_member_specification_opt(tokens, token_i, node3))
            {
                node_t node4;
                if(cpp_parser_shift_token<'}'>(tokens, token_i, node4))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * class_head
 *     class_key identifier_opt base_clause_opt 
 *     class_key nested_name_specifier identifier base_clause_opt 
 ******************************************************************************************/

bool cpp_parser_class_head(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_class_key(tokens, token_i, node1))
    {
        node_t node2;
        switch(GET_TOKEN_ID(tokens, token_i))
        {
        case ':':
        case IDENTIFIER:
            if(cpp_parser_identifier_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_base_clause_opt(tokens, token_i, node3))
                {
                    return true;
                }
            }
            break;

        case CLASS_NAME:
        case NAMESPACE_NAME:
        case TEMPLATE_NAME:
            if(cpp_parser_nested_name_specifier(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_identifier(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_base_clause_opt(tokens, token_i, node4))
                    {
                        return true;
                    }
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
 * class_key
 *     CLASS 
 *     STRUCT 
 *     UNION 
 ******************************************************************************************/

bool cpp_parser_class_key(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case CLASS:
        if(cpp_parser_shift_token<CLASS>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case STRUCT:
        if(cpp_parser_shift_token<STRUCT>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case UNION:
        if(cpp_parser_shift_token<UNION>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * member_specification
 *     member_declaration member_specification_opt 
 *     access_specifier ':' member_specification_opt 
 ******************************************************************************************/

bool cpp_parser_member_specification(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case PRIVATE:
    case PROTECTED:
    case PUBLIC:
        if(cpp_parser_access_specifier(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<':'>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_member_specification_opt(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case '&':
    case '(':
    case '*':
    case ',':
    case ':':
    case ';':
    case '[':
    case '{':
    case '~':
    case AUTO:
    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case EXPLICIT:
    case EXPORT:
    case EXTERN:
    case FLOAT:
    case FRIEND:
    case IDENTIFIER:
    case INLINE:
    case INT:
    case LONG:
    case MUTABLE:
    case NAMESPACE_NAME:
    case OPERATOR:
    case REGISTER:
    case SHORT:
    case SIGNED:
    case STATIC:
    case STRUCT:
    case TEMPLATE:
    case TEMPLATE_NAME:
    case TRY:
    case TYPEDEF:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case USING:
    case VIRTUAL:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_member_declaration(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_member_specification_opt(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * member_declaration
 *     decl_specifier_seq_opt member_declarator_list_opt ';' 
 *     function_definition SEMICOLON_opt 
 *     qualified_id ';' 
 *     using_declaration 
 *     template_declaration 
 ******************************************************************************************/

bool cpp_parser_member_declaration(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '&':
    case '(':
    case '*':
    case ',':
    case ':':
    case ';':
    case '[':
    case '~':
    case AUTO:
    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case EXPLICIT:
    case EXTERN:
    case FLOAT:
    case FRIEND:
    case IDENTIFIER:
    case INLINE:
    case INT:
    case LONG:
    case MUTABLE:
    case NAMESPACE_NAME:
    case OPERATOR:
    case REGISTER:
    case SHORT:
    case SIGNED:
    case STATIC:
    case STRUCT:
    case TEMPLATE:
    case TEMPLATE_NAME:
    case TYPEDEF:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case VIRTUAL:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_decl_specifier_seq_opt(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_member_declarator_list_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<';'>(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }

        token_i = current_i;
        if(cpp_parser_function_definition(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_SEMICOLON_opt(tokens, token_i, node2))
            {
                return true;
            }
        }

        token_i = current_i;
        if(cpp_parser_qualified_id(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<';'>(tokens, token_i, node2))
            {
                return true;
            }
        }

        token_i = current_i;
        if(cpp_parser_template_declaration(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case EXPORT:
        if(cpp_parser_template_declaration(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case USING:
        if(cpp_parser_using_declaration(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * member_declarator_list
 *     member_declarator 
 *     member_declarator_list ',' member_declarator 
 ******************************************************************************************/

bool cpp_parser_member_declarator_list(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '&':
    case '(':
    case '*':
    case ':':
    case '[':
    case '~':
    case CLASS_NAME:
    case COLONCOLON:
    case ENUM_NAME:
    case IDENTIFIER:
    case NAMESPACE_NAME:
    case OPERATOR:
    case TEMPLATE_NAME:
    case TYPEDEF_NAME:
        if(cpp_parser_member_declarator(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_member_declarator_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_member_declarator(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case ',':
        if(cpp_parser_member_declarator_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_member_declarator(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * member_declarator
 *     declarator pure_specifier_opt 
 *     declarator constant_initializer_opt 
 *     identifier_opt ':' constant_expression 
 ******************************************************************************************/

bool cpp_parser_member_declarator(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '&':
    case '(':
    case '*':
    case '[':
    case '~':
    case CLASS_NAME:
    case COLONCOLON:
    case ENUM_NAME:
    case IDENTIFIER:
    case NAMESPACE_NAME:
    case OPERATOR:
    case TEMPLATE_NAME:
    case TYPEDEF_NAME:
        if(cpp_parser_declarator(tokens, token_i, node1))
        {
            node_t node2;
            int current_i = token_i;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '=':
                if(cpp_parser_constant_initializer_opt(tokens, token_i, node2))
                {
                    return true;
                }

                token_i = current_i;
                if(cpp_parser_pure_specifier_opt(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }

        token_i = current_i;
        if(cpp_parser_identifier_opt(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<':'>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_constant_expression(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case ':':
        if(cpp_parser_identifier_opt(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<':'>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_constant_expression(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * pure_specifier
 *     '=' '0' 
 ******************************************************************************************/

bool cpp_parser_pure_specifier(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<'='>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<'0'>(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * constant_initializer
 *     '=' constant_expression 
 ******************************************************************************************/

bool cpp_parser_constant_initializer(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<'='>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_constant_expression(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * base_clause
 *     ':' base_specifier_list 
 ******************************************************************************************/

bool cpp_parser_base_clause(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<':'>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_base_specifier_list(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * base_specifier_list
 *     base_specifier 
 *     base_specifier_list ',' base_specifier 
 ******************************************************************************************/

bool cpp_parser_base_specifier_list(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case CLASS_NAME:
    case COLONCOLON:
    case NAMESPACE_NAME:
    case PRIVATE:
    case PROTECTED:
    case PUBLIC:
    case TEMPLATE_NAME:
    case VIRTUAL:
        if(cpp_parser_base_specifier(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_base_specifier_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_base_specifier(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case ',':
        if(cpp_parser_base_specifier_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_base_specifier(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * base_specifier
 *     COLONCOLON_opt nested_name_specifier_opt class_name 
 *     VIRTUAL access_specifier_opt COLONCOLON_opt nested_name_specifier_opt class_name 
 *     access_specifier VIRTUAL_opt COLONCOLON_opt nested_name_specifier_opt class_name 
 ******************************************************************************************/

bool cpp_parser_base_specifier(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case CLASS_NAME:
    case COLONCOLON:
    case NAMESPACE_NAME:
    case TEMPLATE_NAME:
        if(cpp_parser_COLONCOLON_opt(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_nested_name_specifier_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_class_name(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case VIRTUAL:
        if(cpp_parser_shift_token<VIRTUAL>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_access_specifier_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_COLONCOLON_opt(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_nested_name_specifier_opt(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_class_name(tokens, token_i, node5))
                        {
                            return true;
                        }
                    }
                }
            }
        }
        break;

    case PRIVATE:
    case PROTECTED:
    case PUBLIC:
        if(cpp_parser_access_specifier(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_VIRTUAL_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_COLONCOLON_opt(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_nested_name_specifier_opt(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_class_name(tokens, token_i, node5))
                        {
                            return true;
                        }
                    }
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * access_specifier
 *     PRIVATE 
 *     PROTECTED 
 *     PUBLIC 
 ******************************************************************************************/

bool cpp_parser_access_specifier(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case PRIVATE:
        if(cpp_parser_shift_token<PRIVATE>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case PROTECTED:
        if(cpp_parser_shift_token<PROTECTED>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case PUBLIC:
        if(cpp_parser_shift_token<PUBLIC>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * conversion_function_id
 *     OPERATOR conversion_type_id 
 ******************************************************************************************/

bool cpp_parser_conversion_function_id(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<OPERATOR>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_conversion_type_id(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * conversion_type_id
 *     type_specifier_seq conversion_declarator_opt 
 ******************************************************************************************/

bool cpp_parser_conversion_type_id(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_type_specifier_seq(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_conversion_declarator_opt(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * conversion_declarator
 *     ptr_operator conversion_declarator_opt 
 ******************************************************************************************/

bool cpp_parser_conversion_declarator(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_ptr_operator(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_conversion_declarator_opt(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * ctor_initializer
 *     ':' mem_initializer_list 
 ******************************************************************************************/

bool cpp_parser_ctor_initializer(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<':'>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_mem_initializer_list(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * mem_initializer_list
 *     mem_initializer 
 *     mem_initializer ',' mem_initializer_list 
 ******************************************************************************************/

bool cpp_parser_mem_initializer_list(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_mem_initializer(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<','>(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_mem_initializer_list(tokens, token_i, node3))
            {
                return true;
            }
        }
    }
    return false;
}

/******************************************************************************************
 * mem_initializer
 *     mem_initializer_id '(' expression_list_opt ')' 
 ******************************************************************************************/

bool cpp_parser_mem_initializer(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_mem_initializer_id(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_expression_list_opt(tokens, token_i, node3))
            {
                node_t node4;
                if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * mem_initializer_id
 *     COLONCOLON_opt nested_name_specifier_opt class_name 
 *     identifier 
 ******************************************************************************************/

bool cpp_parser_mem_initializer_id(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case CLASS_NAME:
    case COLONCOLON:
    case NAMESPACE_NAME:
    case TEMPLATE_NAME:
        if(cpp_parser_COLONCOLON_opt(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_nested_name_specifier_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_class_name(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case IDENTIFIER:
        if(cpp_parser_identifier(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * operator_function_id
 *     OPERATOR operator 
 ******************************************************************************************/

bool cpp_parser_operator_function_id(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<OPERATOR>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_operator(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * operator
 *     NEW 
 *     DELETE 
 *     NEW '[' ']' 
 *     DELETE '[' ']' 
 *     '+' 
 *     '_' 
 *     '*' 
 *     '/' 
 *     '%' 
 *     '^' 
 *     '&' 
 *     '|' 
 *     '~' 
 *     '!' 
 *     '=' 
 *     '<' 
 *     '>' 
 *     ADDEQ 
 *     SUBEQ 
 *     MULEQ 
 *     DIVEQ 
 *     MODEQ 
 *     XOREQ 
 *     ANDEQ 
 *     OREQ 
 *     SL 
 *     SR 
 *     SREQ 
 *     SLEQ 
 *     EQ 
 *     NOTEQ 
 *     LTEQ 
 *     GTEQ 
 *     ANDAND 
 *     OROR 
 *     PLUSPLUS 
 *     MINUSMINUS 
 *     ',' 
 *     ARROWSTAR 
 *     ARROW 
 *     '(' ')' 
 *     '[' ']' 
 ******************************************************************************************/

bool cpp_parser_operator(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
        if(cpp_parser_shift_token<'!'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '%':
        if(cpp_parser_shift_token<'%'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '&':
        if(cpp_parser_shift_token<'&'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '(':
        if(cpp_parser_shift_token<'('>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<')'>(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    case '*':
        if(cpp_parser_shift_token<'*'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '+':
        if(cpp_parser_shift_token<'+'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ',':
        if(cpp_parser_shift_token<','>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '/':
        if(cpp_parser_shift_token<'/'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '<':
        if(cpp_parser_shift_token<'<'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '=':
        if(cpp_parser_shift_token<'='>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '>':
        if(cpp_parser_shift_token<'>'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '[':
        if(cpp_parser_shift_token<'['>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<']'>(tokens, token_i, node2))
            {
                return true;
            }
        }
        break;

    case '^':
        if(cpp_parser_shift_token<'^'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '_':
        if(cpp_parser_shift_token<'_'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '|':
        if(cpp_parser_shift_token<'|'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '~':
        if(cpp_parser_shift_token<'~'>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ADDEQ:
        if(cpp_parser_shift_token<ADDEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ANDAND:
        if(cpp_parser_shift_token<ANDAND>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ANDEQ:
        if(cpp_parser_shift_token<ANDEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ARROW:
        if(cpp_parser_shift_token<ARROW>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ARROWSTAR:
        if(cpp_parser_shift_token<ARROWSTAR>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case DELETE:
        if(cpp_parser_shift_token<DELETE>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'['>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<']'>(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case DIVEQ:
        if(cpp_parser_shift_token<DIVEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case EQ:
        if(cpp_parser_shift_token<EQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case GTEQ:
        if(cpp_parser_shift_token<GTEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case LTEQ:
        if(cpp_parser_shift_token<LTEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case MINUSMINUS:
        if(cpp_parser_shift_token<MINUSMINUS>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case MODEQ:
        if(cpp_parser_shift_token<MODEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case MULEQ:
        if(cpp_parser_shift_token<MULEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case NEW:
        if(cpp_parser_shift_token<NEW>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'['>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<']'>(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case NOTEQ:
        if(cpp_parser_shift_token<NOTEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case OREQ:
        if(cpp_parser_shift_token<OREQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case OROR:
        if(cpp_parser_shift_token<OROR>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case PLUSPLUS:
        if(cpp_parser_shift_token<PLUSPLUS>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case SL:
        if(cpp_parser_shift_token<SL>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case SLEQ:
        if(cpp_parser_shift_token<SLEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case SR:
        if(cpp_parser_shift_token<SR>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case SREQ:
        if(cpp_parser_shift_token<SREQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case SUBEQ:
        if(cpp_parser_shift_token<SUBEQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case XOREQ:
        if(cpp_parser_shift_token<XOREQ>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * template_declaration
 *     EXPORT_opt TEMPLATE '<' template_parameter_list '>' declaration 
 ******************************************************************************************/

bool cpp_parser_template_declaration(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_EXPORT_opt(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<TEMPLATE>(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_shift_token<'<'>(tokens, token_i, node3))
            {
                node_t node4;
                if(cpp_parser_template_parameter_list(tokens, token_i, node4))
                {
                    node_t node5;
                    if(cpp_parser_shift_token<'>'>(tokens, token_i, node5))
                    {
                        node_t node6;
                        if(cpp_parser_declaration(tokens, token_i, node6))
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * template_parameter_list
 *     template_parameter 
 *     template_parameter_list ',' template_parameter 
 ******************************************************************************************/

bool cpp_parser_template_parameter_list(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case AUTO:
    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case EXPLICIT:
    case EXTERN:
    case FLOAT:
    case FRIEND:
    case IDENTIFIER:
    case INLINE:
    case INT:
    case LONG:
    case MUTABLE:
    case NAMESPACE_NAME:
    case REGISTER:
    case SHORT:
    case SIGNED:
    case STATIC:
    case STRUCT:
    case TEMPLATE:
    case TEMPLATE_NAME:
    case TYPEDEF:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case VIRTUAL:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_template_parameter(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_template_parameter_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_template_parameter(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case ',':
        if(cpp_parser_template_parameter_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_template_parameter(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * template_parameter
 *     type_parameter 
 *     parameter_declaration 
 ******************************************************************************************/

bool cpp_parser_template_parameter(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case AUTO:
    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case EXPLICIT:
    case EXTERN:
    case FLOAT:
    case FRIEND:
    case IDENTIFIER:
    case INLINE:
    case INT:
    case LONG:
    case MUTABLE:
    case NAMESPACE_NAME:
    case REGISTER:
    case SHORT:
    case SIGNED:
    case STATIC:
    case STRUCT:
    case TEMPLATE_NAME:
    case TYPEDEF:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case VIRTUAL:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_parameter_declaration(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_type_parameter(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case TEMPLATE:
        if(cpp_parser_type_parameter(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * type_parameter
 *     CLASS identifier_opt 
 *     CLASS identifier_opt '=' type_id 
 *     TYPENAME identifier_opt 
 *     TYPENAME identifier_opt '=' type_id 
 *     TEMPLATE '<' template_parameter_list '>' CLASS identifier_opt 
 *     TEMPLATE '<' template_parameter_list '>' CLASS identifier_opt '=' template_name 
 ******************************************************************************************/

bool cpp_parser_type_parameter(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case CLASS:
        if(cpp_parser_shift_token<CLASS>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_identifier_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<'='>(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_type_id(tokens, token_i, node4))
                    {
                        return true;
                    }
                }
            }
        }
        break;

    case TEMPLATE:
        if(cpp_parser_shift_token<TEMPLATE>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<'<'>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_template_parameter_list(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_shift_token<'>'>(tokens, token_i, node4))
                    {
                        node_t node5;
                        if(cpp_parser_shift_token<CLASS>(tokens, token_i, node5))
                        {
                            node_t node6;
                            if(cpp_parser_identifier_opt(tokens, token_i, node6))
                            {
                                node_t node7;
                                if(cpp_parser_shift_token<'='>(tokens, token_i, node7))
                                {
                                    node_t node8;
                                    if(cpp_parser_template_name(tokens, token_i, node8))
                                    {
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        break;

    case TYPENAME:
        if(cpp_parser_shift_token<TYPENAME>(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_identifier_opt(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_shift_token<'='>(tokens, token_i, node3))
                {
                    node_t node4;
                    if(cpp_parser_type_id(tokens, token_i, node4))
                    {
                        return true;
                    }
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * template_id
 *     template_name '<' template_argument_list '>' 
 ******************************************************************************************/

bool cpp_parser_template_id(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_template_name(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<'<'>(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_template_argument_list(tokens, token_i, node3))
            {
                node_t node4;
                if(cpp_parser_shift_token<'>'>(tokens, token_i, node4))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * template_argument_list
 *     template_argument 
 *     template_argument_list ',' template_argument 
 ******************************************************************************************/

bool cpp_parser_template_argument_list(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '=':
    case '>':
    case '[':
    case '^':
    case '|':
    case '~':
    case ADDEQ:
    case ANDAND:
    case ANDEQ:
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case CONST_CAST:
    case DELETE:
    case DIVEQ:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case MODEQ:
    case MULEQ:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case OREQ:
    case OROR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SLEQ:
    case SR:
    case SREQ:
    case STATIC_CAST:
    case STRING:
    case STRUCT:
    case SUBEQ:
    case TEMPLATE_NAME:
    case THIS:
    case THROW:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
    case XOREQ:
        if(cpp_parser_template_argument(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_template_argument_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_template_argument(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case ',':
        if(cpp_parser_template_argument_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_template_argument(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * template_argument
 *     assignment_expression 
 *     type_id 
 *     template_name 
 ******************************************************************************************/

bool cpp_parser_template_argument(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '=':
    case '>':
    case '[':
    case '^':
    case '|':
    case '~':
    case ADDEQ:
    case ANDAND:
    case ANDEQ:
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DIVEQ:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case MODEQ:
    case MULEQ:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case OREQ:
    case OROR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SLEQ:
    case SR:
    case SREQ:
    case STATIC_CAST:
    case STRING:
    case SUBEQ:
    case TEMPLATE_NAME:
    case THIS:
    case THROW:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
    case XOREQ:
        if(cpp_parser_assignment_expression(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_template_name(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_type_id(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case CLASS:
    case CONST:
    case ENUM:
    case STRUCT:
    case TYPENAME:
    case UNION:
    case VOLATILE:
        if(cpp_parser_type_id(tokens, token_i, node1))
        {
            return true;
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * explicit_instantiation
 *     TEMPLATE declaration 
 ******************************************************************************************/

bool cpp_parser_explicit_instantiation(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<TEMPLATE>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_declaration(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * explicit_specialization
 *     TEMPLATE '<' '>' declaration 
 ******************************************************************************************/

bool cpp_parser_explicit_specialization(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<TEMPLATE>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<'<'>(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_shift_token<'>'>(tokens, token_i, node3))
            {
                node_t node4;
                if(cpp_parser_declaration(tokens, token_i, node4))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * try_block
 *     TRY compound_statement handler_seq 
 ******************************************************************************************/

bool cpp_parser_try_block(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<TRY>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_compound_statement(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_handler_seq(tokens, token_i, node3))
            {
                return true;
            }
        }
    }
    return false;
}

/******************************************************************************************
 * function_try_block
 *     TRY ctor_initializer_opt function_body handler_seq 
 ******************************************************************************************/

bool cpp_parser_function_try_block(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<TRY>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_ctor_initializer_opt(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_function_body(tokens, token_i, node3))
            {
                node_t node4;
                if(cpp_parser_handler_seq(tokens, token_i, node4))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * handler_seq
 *     handler handler_seq_opt 
 ******************************************************************************************/

bool cpp_parser_handler_seq(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_handler(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_handler_seq_opt(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * handler
 *     CATCH '(' exception_declaration ')' compound_statement 
 ******************************************************************************************/

bool cpp_parser_handler(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<CATCH>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_exception_declaration(tokens, token_i, node3))
            {
                node_t node4;
                if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                {
                    node_t node5;
                    if(cpp_parser_compound_statement(tokens, token_i, node5))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * exception_declaration
 *     type_specifier_seq declarator 
 *     type_specifier_seq abstract_declarator 
 *     type_specifier_seq 
 *     ELLIPSIS 
 ******************************************************************************************/

bool cpp_parser_exception_declaration(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case ELLIPSIS:
        if(cpp_parser_shift_token<ELLIPSIS>(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case FLOAT:
    case IDENTIFIER:
    case INT:
    case LONG:
    case NAMESPACE_NAME:
    case SHORT:
    case SIGNED:
    case STRUCT:
    case TEMPLATE_NAME:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_type_specifier_seq(tokens, token_i, node1))
        {
            node_t node2;
            int current_i = token_i;
            switch(GET_TOKEN_ID(tokens, token_i))
            {
            case '&':
            case '(':
            case '*':
            case '[':
            case CLASS_NAME:
            case COLONCOLON:
            case NAMESPACE_NAME:
            case TEMPLATE_NAME:
                if(cpp_parser_abstract_declarator(tokens, token_i, node2))
                {
                    return true;
                }

                token_i = current_i;
                if(cpp_parser_declarator(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            case '~':
            case ENUM_NAME:
            case IDENTIFIER:
            case OPERATOR:
            case TYPEDEF_NAME:
                if(cpp_parser_declarator(tokens, token_i, node2))
                {
                    return true;
                }
                break;

            default:
                REPORT_SWITCH_ERROR(tokens, token_i);
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * throw_expression
 *     THROW assignment_expression_opt 
 ******************************************************************************************/

bool cpp_parser_throw_expression(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<THROW>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_assignment_expression_opt(tokens, token_i, node2))
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************************
 * exception_specification
 *     THROW '(' type_id_list_opt ')' 
 ******************************************************************************************/

bool cpp_parser_exception_specification(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    if(cpp_parser_shift_token<THROW>(tokens, token_i, node1))
    {
        node_t node2;
        if(cpp_parser_shift_token<'('>(tokens, token_i, node2))
        {
            node_t node3;
            if(cpp_parser_type_id_list_opt(tokens, token_i, node3))
            {
                node_t node4;
                if(cpp_parser_shift_token<')'>(tokens, token_i, node4))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

/******************************************************************************************
 * type_id_list
 *     type_id 
 *     type_id_list ',' type_id 
 ******************************************************************************************/

bool cpp_parser_type_id_list(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    int current_i = token_i;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case FLOAT:
    case IDENTIFIER:
    case INT:
    case LONG:
    case NAMESPACE_NAME:
    case SHORT:
    case SIGNED:
    case STRUCT:
    case TEMPLATE_NAME:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_type_id(tokens, token_i, node1))
        {
            return true;
        }

        token_i = current_i;
        if(cpp_parser_type_id_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_type_id(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    case ',':
        if(cpp_parser_type_id_list(tokens, token_i, node1))
        {
            node_t node2;
            if(cpp_parser_shift_token<','>(tokens, token_i, node2))
            {
                node_t node3;
                if(cpp_parser_type_id(tokens, token_i, node3))
                {
                    return true;
                }
            }
        }
        break;

    default:
        REPORT_SWITCH_ERROR(tokens, token_i);
    }
    return false;
}

/******************************************************************************************
 * declaration_seq_opt
 *     <<empty>>
 *     declaration_seq 
 ******************************************************************************************/

bool cpp_parser_declaration_seq_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '&':
    case '(':
    case '*':
    case ',':
    case ':':
    case ';':
    case '[':
    case '{':
    case '~':
    case ASM:
    case AUTO:
    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case EXPLICIT:
    case EXPORT:
    case EXTERN:
    case FLOAT:
    case FRIEND:
    case IDENTIFIER:
    case INLINE:
    case INT:
    case LONG:
    case MUTABLE:
    case NAMESPACE:
    case NAMESPACE_NAME:
    case OPERATOR:
    case REGISTER:
    case SHORT:
    case SIGNED:
    case STATIC:
    case STRUCT:
    case TEMPLATE:
    case TEMPLATE_NAME:
    case TRY:
    case TYPEDEF:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case USING:
    case VIRTUAL:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_declaration_seq(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * TEMPLATE_opt
 *     <<empty>>
 *     TEMPLATE 
 ******************************************************************************************/

bool cpp_parser_TEMPLATE_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case TEMPLATE:
        if(cpp_parser_shift_token<TEMPLATE>(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * nested_name_specifier_opt
 *     <<empty>>
 *     nested_name_specifier 
 ******************************************************************************************/

bool cpp_parser_nested_name_specifier_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case CLASS_NAME:
    case NAMESPACE_NAME:
    case TEMPLATE_NAME:
        if(cpp_parser_nested_name_specifier(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * expression_list_opt
 *     <<empty>>
 *     expression_list 
 ******************************************************************************************/

bool cpp_parser_expression_list_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case ',':
    case '-':
    case '.':
    case '/':
    case '<':
    case '=':
    case '>':
    case '[':
    case '^':
    case '|':
    case '~':
    case ADDEQ:
    case ANDAND:
    case ANDEQ:
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DIVEQ:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case MODEQ:
    case MULEQ:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case OREQ:
    case OROR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SLEQ:
    case SR:
    case SREQ:
    case STATIC_CAST:
    case STRING:
    case SUBEQ:
    case TEMPLATE_NAME:
    case THIS:
    case THROW:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
    case XOREQ:
        if(cpp_parser_expression_list(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * COLONCOLON_opt
 *     <<empty>>
 *     COLONCOLON 
 ******************************************************************************************/

bool cpp_parser_COLONCOLON_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case COLONCOLON:
        if(cpp_parser_shift_token<COLONCOLON>(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * new_placement_opt
 *     <<empty>>
 *     new_placement 
 ******************************************************************************************/

bool cpp_parser_new_placement_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '(':
        if(cpp_parser_new_placement(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * new_initializer_opt
 *     <<empty>>
 *     new_initializer 
 ******************************************************************************************/

bool cpp_parser_new_initializer_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '(':
        if(cpp_parser_new_initializer(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * new_declarator_opt
 *     <<empty>>
 *     new_declarator 
 ******************************************************************************************/

bool cpp_parser_new_declarator_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '&':
    case '*':
    case '[':
    case CLASS_NAME:
    case COLONCOLON:
    case NAMESPACE_NAME:
    case TEMPLATE_NAME:
        if(cpp_parser_new_declarator(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * expression_opt
 *     <<empty>>
 *     expression 
 ******************************************************************************************/

bool cpp_parser_expression_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case ',':
    case '-':
    case '.':
    case '/':
    case '<':
    case '=':
    case '>':
    case '[':
    case '^':
    case '|':
    case '~':
    case ADDEQ:
    case ANDAND:
    case ANDEQ:
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DIVEQ:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case MODEQ:
    case MULEQ:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case OREQ:
    case OROR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SLEQ:
    case SR:
    case SREQ:
    case STATIC_CAST:
    case STRING:
    case SUBEQ:
    case TEMPLATE_NAME:
    case THIS:
    case THROW:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
    case XOREQ:
        if(cpp_parser_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * statement_seq_opt
 *     <<empty>>
 *     statement_seq 
 ******************************************************************************************/

bool cpp_parser_statement_seq_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case ',':
    case '-':
    case '.':
    case '/':
    case ':':
    case ';':
    case '<':
    case '=':
    case '>':
    case '[':
    case '^':
    case '{':
    case '|':
    case '~':
    case ADDEQ:
    case ANDAND:
    case ANDEQ:
    case ARROW:
    case ARROWSTAR:
    case ASM:
    case AUTO:
    case BOOL:
    case BREAK:
    case CASE:
    case CHAR:
    case CHARACTER:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case CONST_CAST:
    case CONTINUE:
    case DEFAULT:
    case DELETE:
    case DIVEQ:
    case DO:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM:
    case ENUM_NAME:
    case EQ:
    case EXPLICIT:
    case EXTERN:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case FOR:
    case FRIEND:
    case GOTO:
    case GTEQ:
    case IDENTIFIER:
    case IF:
    case INLINE:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case MODEQ:
    case MULEQ:
    case MUTABLE:
    case NAMESPACE:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case OREQ:
    case OROR:
    case PLUSPLUS:
    case REGISTER:
    case REINTERPRET_CAST:
    case RETURN:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SLEQ:
    case SR:
    case SREQ:
    case STATIC:
    case STATIC_CAST:
    case STRING:
    case STRUCT:
    case SUBEQ:
    case SWITCH:
    case TEMPLATE:
    case TEMPLATE_NAME:
    case THIS:
    case THROW:
    case TRUE:
    case TRY:
    case TYPEDEF:
    case TYPEDEF_NAME:
    case TYPEID:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case USING:
    case VIRTUAL:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
    case WHILE:
    case XOREQ:
        if(cpp_parser_statement_seq(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * condition_opt
 *     <<empty>>
 *     condition 
 ******************************************************************************************/

bool cpp_parser_condition_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case ',':
    case '-':
    case '.':
    case '/':
    case '<':
    case '=':
    case '>':
    case '[':
    case '^':
    case '|':
    case '~':
    case ADDEQ:
    case ANDAND:
    case ANDEQ:
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case CONST_CAST:
    case DELETE:
    case DIVEQ:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case MODEQ:
    case MULEQ:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case OREQ:
    case OROR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SLEQ:
    case SR:
    case SREQ:
    case STATIC_CAST:
    case STRING:
    case STRUCT:
    case SUBEQ:
    case TEMPLATE_NAME:
    case THIS:
    case THROW:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
    case XOREQ:
        if(cpp_parser_condition(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * decl_specifier_seq_opt
 *     <<empty>>
 *     decl_specifier_seq 
 ******************************************************************************************/

bool cpp_parser_decl_specifier_seq_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case AUTO:
    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case EXPLICIT:
    case EXTERN:
    case FLOAT:
    case FRIEND:
    case IDENTIFIER:
    case INLINE:
    case INT:
    case LONG:
    case MUTABLE:
    case NAMESPACE_NAME:
    case REGISTER:
    case SHORT:
    case SIGNED:
    case STATIC:
    case STRUCT:
    case TEMPLATE_NAME:
    case TYPEDEF:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case VIRTUAL:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_decl_specifier_seq(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * init_declarator_list_opt
 *     <<empty>>
 *     init_declarator_list 
 ******************************************************************************************/

bool cpp_parser_init_declarator_list_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '&':
    case '(':
    case '*':
    case ',':
    case '[':
    case '~':
    case CLASS_NAME:
    case COLONCOLON:
    case ENUM_NAME:
    case IDENTIFIER:
    case NAMESPACE_NAME:
    case OPERATOR:
    case TEMPLATE_NAME:
    case TYPEDEF_NAME:
        if(cpp_parser_init_declarator_list(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * identifier_opt
 *     <<empty>>
 *     identifier 
 ******************************************************************************************/

bool cpp_parser_identifier_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case IDENTIFIER:
        if(cpp_parser_identifier(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * enumerator_list_opt
 *     <<empty>>
 *     enumerator_list 
 ******************************************************************************************/

bool cpp_parser_enumerator_list_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ',':
    case IDENTIFIER:
        if(cpp_parser_enumerator_list(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * TYPENAME_opt
 *     <<empty>>
 *     TYPENAME 
 ******************************************************************************************/

bool cpp_parser_TYPENAME_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case TYPENAME:
        if(cpp_parser_shift_token<TYPENAME>(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * initializer_opt
 *     <<empty>>
 *     initializer 
 ******************************************************************************************/

bool cpp_parser_initializer_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '(':
    case '=':
        if(cpp_parser_initializer(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * cv_qualifier_seq_opt
 *     <<empty>>
 *     cv_qualifier_seq 
 ******************************************************************************************/

bool cpp_parser_cv_qualifier_seq_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case CONST:
    case VOLATILE:
        if(cpp_parser_cv_qualifier_seq(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * exception_specification_opt
 *     <<empty>>
 *     exception_specification 
 ******************************************************************************************/

bool cpp_parser_exception_specification_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case THROW:
        if(cpp_parser_exception_specification(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * constant_expression_opt
 *     <<empty>>
 *     constant_expression 
 ******************************************************************************************/

bool cpp_parser_constant_expression_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '>':
    case '[':
    case '^':
    case '|':
    case '~':
    case ANDAND:
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case OROR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SR:
    case STATIC_CAST:
    case STRING:
    case TEMPLATE_NAME:
    case THIS:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
        if(cpp_parser_constant_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * abstract_declarator_opt
 *     <<empty>>
 *     abstract_declarator 
 ******************************************************************************************/

bool cpp_parser_abstract_declarator_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '&':
    case '(':
    case '*':
    case '[':
    case CLASS_NAME:
    case COLONCOLON:
    case NAMESPACE_NAME:
    case TEMPLATE_NAME:
        if(cpp_parser_abstract_declarator(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * type_specifier_seq_opt
 *     <<empty>>
 *     type_specifier_seq 
 ******************************************************************************************/

bool cpp_parser_type_specifier_seq_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case FLOAT:
    case IDENTIFIER:
    case INT:
    case LONG:
    case NAMESPACE_NAME:
    case SHORT:
    case SIGNED:
    case STRUCT:
    case TEMPLATE_NAME:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_type_specifier_seq(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * direct_abstract_declarator_opt
 *     <<empty>>
 *     direct_abstract_declarator 
 ******************************************************************************************/

bool cpp_parser_direct_abstract_declarator_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '(':
    case '[':
        if(cpp_parser_direct_abstract_declarator(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * parameter_declaration_list_opt
 *     <<empty>>
 *     parameter_declaration_list 
 ******************************************************************************************/

bool cpp_parser_parameter_declaration_list_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ',':
    case AUTO:
    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case EXPLICIT:
    case EXTERN:
    case FLOAT:
    case FRIEND:
    case IDENTIFIER:
    case INLINE:
    case INT:
    case LONG:
    case MUTABLE:
    case NAMESPACE_NAME:
    case REGISTER:
    case SHORT:
    case SIGNED:
    case STATIC:
    case STRUCT:
    case TEMPLATE_NAME:
    case TYPEDEF:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case VIRTUAL:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_parameter_declaration_list(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * ELLIPSIS_opt
 *     <<empty>>
 *     ELLIPSIS 
 ******************************************************************************************/

bool cpp_parser_ELLIPSIS_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ELLIPSIS:
        if(cpp_parser_shift_token<ELLIPSIS>(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * ctor_initializer_opt
 *     <<empty>>
 *     ctor_initializer 
 ******************************************************************************************/

bool cpp_parser_ctor_initializer_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ':':
        if(cpp_parser_ctor_initializer(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * COMMA_opt
 *     <<empty>>
 *     ',' 
 ******************************************************************************************/

bool cpp_parser_COMMA_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ',':
        if(cpp_parser_shift_token<','>(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * member_specification_opt
 *     <<empty>>
 *     member_specification 
 ******************************************************************************************/

bool cpp_parser_member_specification_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '&':
    case '(':
    case '*':
    case ',':
    case ':':
    case ';':
    case '[':
    case '{':
    case '~':
    case AUTO:
    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case EXPLICIT:
    case EXPORT:
    case EXTERN:
    case FLOAT:
    case FRIEND:
    case IDENTIFIER:
    case INLINE:
    case INT:
    case LONG:
    case MUTABLE:
    case NAMESPACE_NAME:
    case OPERATOR:
    case PRIVATE:
    case PROTECTED:
    case PUBLIC:
    case REGISTER:
    case SHORT:
    case SIGNED:
    case STATIC:
    case STRUCT:
    case TEMPLATE:
    case TEMPLATE_NAME:
    case TRY:
    case TYPEDEF:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case USING:
    case VIRTUAL:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_member_specification(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * base_clause_opt
 *     <<empty>>
 *     base_clause 
 ******************************************************************************************/

bool cpp_parser_base_clause_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ':':
        if(cpp_parser_base_clause(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * member_declarator_list_opt
 *     <<empty>>
 *     member_declarator_list 
 ******************************************************************************************/

bool cpp_parser_member_declarator_list_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '&':
    case '(':
    case '*':
    case ',':
    case ':':
    case '[':
    case '~':
    case CLASS_NAME:
    case COLONCOLON:
    case ENUM_NAME:
    case IDENTIFIER:
    case NAMESPACE_NAME:
    case OPERATOR:
    case TEMPLATE_NAME:
    case TYPEDEF_NAME:
        if(cpp_parser_member_declarator_list(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * SEMICOLON_opt
 *     <<empty>>
 *     ';' 
 ******************************************************************************************/

bool cpp_parser_SEMICOLON_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ';':
        if(cpp_parser_shift_token<';'>(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * pure_specifier_opt
 *     <<empty>>
 *     pure_specifier 
 ******************************************************************************************/

bool cpp_parser_pure_specifier_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '=':
        if(cpp_parser_pure_specifier(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * constant_initializer_opt
 *     <<empty>>
 *     constant_initializer 
 ******************************************************************************************/

bool cpp_parser_constant_initializer_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '=':
        if(cpp_parser_constant_initializer(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * access_specifier_opt
 *     <<empty>>
 *     access_specifier 
 ******************************************************************************************/

bool cpp_parser_access_specifier_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case PRIVATE:
    case PROTECTED:
    case PUBLIC:
        if(cpp_parser_access_specifier(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * VIRTUAL_opt
 *     <<empty>>
 *     VIRTUAL 
 ******************************************************************************************/

bool cpp_parser_VIRTUAL_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case VIRTUAL:
        if(cpp_parser_shift_token<VIRTUAL>(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * conversion_declarator_opt
 *     <<empty>>
 *     conversion_declarator 
 ******************************************************************************************/

bool cpp_parser_conversion_declarator_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '&':
    case '*':
    case CLASS_NAME:
    case COLONCOLON:
    case NAMESPACE_NAME:
    case TEMPLATE_NAME:
        if(cpp_parser_conversion_declarator(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * EXPORT_opt
 *     <<empty>>
 *     EXPORT 
 ******************************************************************************************/

bool cpp_parser_EXPORT_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case EXPORT:
        if(cpp_parser_shift_token<EXPORT>(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * handler_seq_opt
 *     <<empty>>
 *     handler_seq 
 ******************************************************************************************/

bool cpp_parser_handler_seq_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case CATCH:
        if(cpp_parser_handler_seq(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * assignment_expression_opt
 *     <<empty>>
 *     assignment_expression 
 ******************************************************************************************/

bool cpp_parser_assignment_expression_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case '!':
    case '%':
    case '&':
    case '(':
    case '*':
    case '+':
    case '-':
    case '.':
    case '/':
    case '<':
    case '=':
    case '>':
    case '[':
    case '^':
    case '|':
    case '~':
    case ADDEQ:
    case ANDAND:
    case ANDEQ:
    case ARROW:
    case ARROWSTAR:
    case BOOL:
    case CHAR:
    case CHARACTER:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST_CAST:
    case DELETE:
    case DIVEQ:
    case DOTSTAR:
    case DOUBLE:
    case DYNAMIC_CAST:
    case ENUM_NAME:
    case EQ:
    case FALSE:
    case FLOAT:
    case FLOATING:
    case GTEQ:
    case IDENTIFIER:
    case INT:
    case INTEGER:
    case LONG:
    case LTEQ:
    case MINUSMINUS:
    case MODEQ:
    case MULEQ:
    case NAMESPACE_NAME:
    case NEW:
    case NOTEQ:
    case OPERATOR:
    case OREQ:
    case OROR:
    case PLUSPLUS:
    case REINTERPRET_CAST:
    case SHORT:
    case SIGNED:
    case SIZEOF:
    case SL:
    case SLEQ:
    case SR:
    case SREQ:
    case STATIC_CAST:
    case STRING:
    case SUBEQ:
    case TEMPLATE_NAME:
    case THIS:
    case THROW:
    case TRUE:
    case TYPEDEF_NAME:
    case TYPEID:
    case UNSIGNED:
    case VOID:
    case WCHAR_T:
    case XOREQ:
        if(cpp_parser_assignment_expression(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}

/******************************************************************************************
 * type_id_list_opt
 *     <<empty>>
 *     type_id_list 
 ******************************************************************************************/

bool cpp_parser_type_id_list_opt(const token_t * tokens, int & token_i, node_t & node)
{
    node_t node1;
    switch(GET_TOKEN_ID(tokens, token_i))
    {
    default:
        if(cpp_parser_shift_EMPTY(tokens, token_i, node1))
        {
            return true;
        }
        break;

    case ',':
    case BOOL:
    case CHAR:
    case CLASS:
    case CLASS_NAME:
    case COLONCOLON:
    case CONST:
    case DOUBLE:
    case ENUM:
    case ENUM_NAME:
    case FLOAT:
    case IDENTIFIER:
    case INT:
    case LONG:
    case NAMESPACE_NAME:
    case SHORT:
    case SIGNED:
    case STRUCT:
    case TEMPLATE_NAME:
    case TYPEDEF_NAME:
    case TYPENAME:
    case UNION:
    case UNSIGNED:
    case VOID:
    case VOLATILE:
    case WCHAR_T:
        if(cpp_parser_type_id_list(tokens, token_i, node1))
        {
            return true;
        }
        break;
    }
    return false;
}
