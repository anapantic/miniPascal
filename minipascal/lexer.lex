%option noyywrap
%option noinput
%option nounput
%{
    #include <iostream>
    #include <cstdlib>
    #include <string>
    #include <cctype>
    #include <stdio.h>
    
    using namespace std;
    
    #include "naredba.hpp"
    #include "izrazi.hpp"
    #include "parser.tab.hpp"
%}


%%
"pocetak"   return pocetak_token;
"kraj"  return kraj_token;
"ispisi"    return ispisi_token;
"mod"   return mod_token;
"ako_je"    return ako_je_token;
"onda"  return onda_token;
"inace" return inace_token;
"unesi" return unesi_token;
"dok_je"    return dok_je_token;
"radi_sledece"  return radi_sledece_token;
":="    return dodela_token;
[0-9]+  {
    yylval.d = atoi(yytext);
    return num_token;
}
"0x"[0-9A-Fa-f]+    {
    sscanf(yytext, "%x", &yylval.d);
    return num_token;
}
[a-zA-Z_][a-zA-Z_0-9]*  {
    for(unsigned i = 0; yytext[i] ; i++)
        yytext[i] = tolower(yytext[i]);
    
    yylval.s = new string(yytext);
    return id_token;
}
[\"][^\"]*[\"]  {
    string tmp(yytext);
    tmp = tmp.substr(1, tmp.size()-2);
    yylval.s = new string(tmp);
    return string_token;
}
[-+*/;.():<>]    return *yytext;
[ \t\n] {}
.   {
    cerr<<"Leksicka greska: neprepoznat karakter '"<<*yytext<<"'\n";
    exit(EXIT_FAILURE);
}
%%