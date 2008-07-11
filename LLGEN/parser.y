
%token PERCENTPERCENT PERCENTTOKEN PERCENTOTHER

%token IDENTIFIER CHARACTER

%%

translate_unit:
	token_seq_opt PERCENTPERCENT production_seq_opt PERCENTPERCENT
	;
	
token_seq:
	PERCENTTOKEN identifier_seq token_seq_opt
	;
	
token_seq_opt:
	/* empty */
	| token_seq
	;
	
identifier_seq:
	IDENTIFIER identifier_seq_opt
	;
	
identifier_seq_opt:
	/* empty */
	| identifier_seq
	;
	
production_seq:
	IDENTIFIER ':' production_rhs production_seq_opt
	;
	
production_seq_opt:
	/* empty */
	| production_seq
	;
	
production_rhs:
	symbol_seq_opt '|' production_rhs
	| symbol_seq_opt ';'
	;
	
symbol_seq:
	symbol symbol_seq_opt
	;
	
symbol_seq_opt:
	/* empty */
	| symbol_seq
	;
	
symbol:
	IDENTIFIER
	| CHARACTER
	;
	
%%
