#include <std.h>

inherit OBJECT;

#define VALID_TOKENS ({ "copper","silver","gold","platinum" })

nosave mapping TOKEN_COLORS = ([ 
    "copper" : "%^RESET%^%^ORANGE%^copper%^RESET%^%^BOLD%^%^GREEN%^", 
    "silver" : "%^RESET%^%^BOLD%^silver%^RESET%^%^BOLD%^%^GREEN%^", 
    "gold" : "%^RESET%^%^YELLOW%^gold%^RESET%^%^BOLD%^GREEN%^", 
    "platinum" : "%^RESET%^platinum%^RESET%^%^BOLD%^%^GREEN%^" ]);

void setup_token();
void set_token_type(string type);
string get_token_type();

string token_type;

void create()
{
    ::create();
    set_id(({"token","single_token9999"}));
    set_short("a token");
    set_weight(1);
}

int isMagic() { return 1; }

void setup_token()
{
    string str,word;
    str = get_token_type();

    set_name(""+str+" token");
    word = TOKEN_COLORS[str];

    TO->set_long("%^RESET%^%^BOLD%^%^GREEN%^This token looks like a thick coin with a polished glass "
        "encasing around the edges.  In the center an exquisitely detailed "+word+" dragon's head "
        "has been carefully engraved.  On the reverse side of the token a laden wagon has been "
        "engraved just as carefully in the same "+word+" metal.");
    TO->set_short("%^RESET%^%^BOLD%^%^GREEN%^A "+word+" colored token");
    TO->set_obvious_short("%^RESET%^%^BOLD%^%^GREEN%^A "+word+" colored token");
    return;
}

void set_token_type(string type)
{
    if(!stringp(type)) { return; }
    if(member_array(type,VALID_TOKENS) == -1) { return; }
    token_type = type;
    setup_token();
    add_id(type+" token");
    return;
}

string get_token_type() { return token_type; }
