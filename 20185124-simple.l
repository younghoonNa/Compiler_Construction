/***************************************************************************
                   Scanner for the Simple language
***************************************************************************/
%{
#include <string.h>
#include "20185124-simple.tab.h"
/*=========================================================================
       C-libraries and Token definitions
  =========================================================================*/
 /* for token definitions and yylval */
%}
/*=========================================================================
       TOKEN Definitions
  =========================================================================*/
DIGIT [0-9]
ID [a-z][a-z0-9]*
/*=========================================================================
       REGULAR EXPRESSIONS defining the tokens for the Simple language
  =========================================================================*/
%option noyywrap
%%
":="     { return(ASSGNOP);   }
{DIGIT}+ { yylval.intval = atoi( yytext ); return(NUMBER); }
do       { return(DO);        }
else     { return(ELSE);      }
end      { return(END);       }
fi       { return(FI);        }
if       { return(IF);        }
in       { return(IN);        }
integer  { return(INTEGER);   }
let      { return(LET);       }
read     { return(READ);      }
skip     { return(SKIP);      }
then     { return(THEN);      }
while    { return(WHILE);     }
write    { return(WRITE);     }
{ID}     { yylval.id = (char *) strdup(yytext);
		return(IDENTIFIER); }
[ \t\n]+ /* eat up whitespace */
.        { return(yytext[0]); }
%%

/************************** End Scanner File *****************************/

