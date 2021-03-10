#include <std.h>
#include <move.h>
#include "token_hunt.h"

inherit OBJECT;

#define TOKEN_VALUE ([ "copper" : 1, "silver" : 100, "gold" : 10000, "platinum" : 1000000 ])

mapping tokens;

void create()
{
    tokens = ([ "copper"     : 0,
                "silver"     : 0,
                "gold"       : 0,
                "platinum"   : 0,    
    ]);
    ::create();
    set_id(({"tokens","box","box of tokens","box for tokens","small box for tokens","token_obj9999"}));
    set_name("Box of Tokens");
    set_short("%^RESET%^%^BOLD%^%^GREEN%^A small box for %^YELLOW%^tokens%^RESET%^");
    set_weight(5);
    set_long("%^RESET%^%^ORANGE%^The outside of this small, narrow box is made of several "
        "pressed layers of %^GREEN%^b%^ORANGE%^e%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^ch"
        "%^ORANGE%^n%^BOLD%^%^BLACK%^u%^RESET%^%^GREEN%^t %^ORANGE%^wood. This gives "
        "the surface a %^BOLD%^%^BLACK%^rough %^RESET%^%^ORANGE%^and %^RESET%^grainy "
        "%^ORANGE%^texture against the skin, but keeps the box light while retaining "
        "a sturdy, damage resistant structure. Metal fixtures have been set at each "
        "of the corners to further strengthen the box. A matching hasp and inner set "
        "of hinges keep the lid safely secured and prevent the contents from spilling "
        "out. Inside, the box has been split into four compartments, each of similar "
        "size. The inner compartments are each about an inch wide and are long and "
        "narrow suggesting that coins of some type might be stacked up within them. "
        "Lined with differing %^BOLD%^%^WHITE%^s%^YELLOW%^h%^RESET%^a%^ORANGE%^d%^RESET%^"
        "e%^YELLOW%^s %^RESET%^%^ORANGE%^of soft velvet, suggestive of what type of coin "
        "might rest in each section, the compartments would appear to hold about a "
        "hundred thick coins each, though they would have to be coins much wider then "
        "the common currency of the realm.\n%^RESET%^%^BOLD%^There is some writing on "
        "the box.%^RESET%^");
    set_value(0);

}

mapping token_map() { return tokens; }

void set_token_map(mapping map) { tokens = map; }

int query_tokens(string type)
{
    if(!intp(tokens[type])) { return 0; }
    return tokens[type];
}

// set_tokens("tokens gold 1")
int set_tokens(string str)
{
    string *info=({});
    if(!avatarp(TP)) { return 0; }
    if(!stringp(str)) { return 0; }
    info = explode(str," ");
    if(sizeof(info) != 3) { return 0; }
    if(info[0] != "token" && info[0] != "tokens") { return 0; }
    if(member_array(info[1],keys(TOKEN_VALUE)) == -1) { return 0; }
    if(!intp(to_int(info[2]))) { return 0; }
    tokens[info[1]] = to_int(info[2]);
    tell_object(ETO,"You set the "+info[1]+" tokens to "+info[2]+"");
    TOKEN_D->set_player_tokens(TP,tokens);
    return 1;
} 

int mod_tokens(string str)
{
    string *info=({});
    if(!stringp(str)) { return 0; }
    info = explode(str," ");
    if(sizeof(info) != 3) { return 0; }
    if(info[0] != "token" && info[0] != "tokens") { return 0; }
    if(member_array(info[1],keys(TOKEN_VALUE)) == -1) { return 0; }
    if(!intp(to_int(info[2]))) { return 0; }
    tokens[info[1]] = to_int(info[2]);
    return 1;
}    

int add_token(string str)
{
    object ob;
    string type,*tmp=({});
    if(!stringp(str) || str == "" || str == " ") { return 0; }
    str = replace_string(str,"to box","");
    if(!objectp(ob=present(str,TP))) { return 0; }
    if(ob->id("token_obj9999"))
    {
        ob->set_id(({"tokens","box","box of tokens","box for tokens","small box for tokens","token_obj9999"}));
    }
    if(!objectp(ob=present(str,TP))) { return 0; }
    if(!ob->id("single_token9999")) { return 0; }
    type = ob->get_token_type();
    tmp = keys(tokens);
    if(member_array(type,tmp) == -1) { return 0; }
    tokens[type] += 1;
    tell_object(ETO,"You add a "+type+" token to your token box.");
    TOKEN_D->set_player_tokens(TP,tokens);
    ob->move("/d/shadowgate/void");
    ob->remove();
    return 1;
}

int calculate_value()
{
    string *types=({});
    int i,num;
    types = keys(tokens);
    for(i=0;i<sizeof(types);i++)
    {
        if(!intp(tokens[types[i]])) { continue; }
        num += TOKEN_VALUE[types[i]] * tokens[types[i]];
    }
    return num;
}

// a little heavy on the looping but it does seem to work
int convert_tokens(string type,int amt)
{
    int j,i=0,hold,num;
    mapping tmp = ([ "copper" : 0, "silver" : 0, "gold" : 0, "platinum" : 0 ]);
    string *keys=({"platinum","gold","silver","copper"});

    hold = TOKEN_VALUE[type] * amt;

    num = calculate_value() - hold;

    while(num)
    {
        j++;
        if(j > 999) { return 99999; }
        hold = TOKEN_VALUE[keys[i]];
        if(num / hold)
        {
            tmp[keys[i]] += 1;
            num -= hold;
        }
        else 
        {
            i++;
        }
    }
    tmp[type] += amt;
    tokens = tmp;
    return 1;
}

int enough_tokens(string type,int amt)
{
    string *types=({});
    int total_value;

    if(!amt || amt < 0) { return 0; }
    if(member_array(type,keys(TOKEN_VALUE)) == -1) { return 0; }
    
    total_value = TOKEN_VALUE[type] * amt;

    if(calculate_value() < total_value) { return 0; }
    
    if(tokens[type] < amt)
    {
        convert_tokens(type,amt);
    }
    return 1;
}

int spend_tokens(string type,int amt)
{
    if(!enough_tokens(type,amt)) { return 0; }
    if(!amt > 0) { return 0; }
    tokens[type] -= amt;
    TOKEN_D->set_player_tokens(TP,tokens);
    return 1;
}

int show_tokens()
{
    int i;
    string *tmp=({});
    tmp = ({ "copper","silver","gold","platinum" });

    tell_object(TP,"%^BOLD%^%^CYAN%^In your box you find these tokens:%^RESET%^");
    tell_object(TP,"%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");

    for(i=0;i<sizeof(tmp);i++)
    {
        tell_object(TP,"%^BOLD%^%^MAGENTA%^     "+arrange_string(tmp[i],10)+"%^RESET%^%^CYAN%^:%^RESET%^%^GREEN%^  "+tokens[tmp[i]]+"%^RESET%^");
    }

    tell_object(TP,"%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");    
    TOKEN_D->set_player_tokens(TP,tokens);
    return 1;
}

int read_box(string str)
{
    if(!stringp(str)) { return 0; }
    if(str != "box" && str != "Box") { return 0; }
    tell_object(TP,"This is a magical token box.  It is used to store "
        "tokens and will even change them into different types, of the "
        "same value of course.  It only changes them when it needs "
        "them at a store.  You can <add token> to the box if you should "
        "happen to find a token.  You can use <tokens> to see how "
        "many tokens are currently in your box.  You can also "
        "<exchange NUMBER TYPE tokens with PLAYER>, or <give NUMBER "
        "TYPE tokens to player> to give another player some of your "
        "tokens.  You may <produce TYPE token> to take a token out of "
        "your token box.");
    if(avatarp(TP))
    {
        tell_object(TP,"%^BOLD%^If you are an immortal, you can use "
            "set tokens <type> <amount> to set the amount of tokens "
            "in your token box.  You may also type showtokens <player> to "
            "see how many tokens <player> last had in their box.");
    }
    return 1;
}

int exchange_tokens(string str)
{
    object ob,box;
    string *info=({}),*check=({});
    int num,count;
    if(!stringp(str)) { return 0; }
    if(!objectp(TO)) { return 0; }
    if(!objectp(ETO)) { return 0; }
    if(!objectp(EETO)) { return 0; }
    if(!userp(ETO)) { return 0; } // prevent box storage on followers then handing them to players
    //exchange 500 silver tokens with fred
    info = explode(str," ");
    if(sizeof(info) != 5) { return 0; }
    if(!intp(num = to_int(info[0]))) { return 0 ; }
    check = keys(tokens);
    if(member_array(info[1],check) == -1) { return 0; }
    if(info[2] != "tokens" && info[2] != "token") { return 0; }
    if(info[3] != "with" && info[3] != "to") { return 0; }
    if(!objectp(ob = present(info[4],EETO))) 
    {
        tell_object(TP,""+info[4]+" isn't here.");
        return 1; 
    }
    if(!objectp(box = present("token_obj9999",ob)))
    {
        tell_object(TP,""+info[4]+" doesn't have a token box.");
        return 1;
    }
    if(!enough_tokens(info[1],num)) {
        tell_object(TP,"You don't have enough tokens.");
        return 1;
    }
    if(!spend_tokens(info[1],num))
    {
        tell_object(TP,"You don't have "+num+" "+info[1]+" tokens.");
        return 1;
    }
    count = box->query_tokens(info[1]);
    count += num;
    box->mod_tokens(""+info[2]+" "+info[1]+" "+count+"");
    tell_object(TP,"You give "+num+" "+info[1]+" tokens to "+info[4]+"");
    tell_object(ob,""+TP->QCN+" gives you "+num+" "+info[1]+" tokens.");
    TOKEN_D->set_player_tokens(TP,tokens);
    return 1;
}

int produce_token(string str)
{
    object ob;
    string *info=({});
    if(!stringp(str)) { return 0; }
    info = explode(str," ");
    if(sizeof(info) != 2) { return 0; }
    if(member_array(info[0],keys(tokens)) == -1) { return 0; }
    if(info[1] != "token" && info[1] != "tokens") { return 0; }
    if(!spend_tokens(info[0],1))
    {
        tell_object(TP,"You don't have enough tokens to equal 1 "+info[0]+" token");
        return 1;
    }
    tell_object(TP,"You pull a "+info[0]+" token from your token box.");
    ob = new(FILE_PATH"single_token");
    ob->set_token_type(info[0]);
    if(ob->move(TP) != MOVE_OK)
    {
        tell_object(TP,"You drop your token on the ground!");
        ob->move(ETP);
    }
    TOKEN_D->set_player_tokens(TP,tokens);
    return 1;
}

int showtokens(string str)
{
    mapping map;
    string *tmp=({});
    int i;
    if(!stringp(str)) { return 0; }
    if(!avatarp(TP)) { return 0; }
    if(!mapp(map = TOKEN_D->get_player_tokens(str)))
    {
        tell_object(TP,"Can't seem to find any tokens for "+str+"");
        return 1;
    }
    tmp = ({ "copper","silver","gold","platinum" });

    tell_object(TP,"%^BOLD%^%^CYAN%^"+capitalize(str)+" last had these tokens:%^RESET%^");
    tell_object(TP,"%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");

    for(i=0;i<sizeof(tmp);i++)
    {
        tell_object(TP,"%^BOLD%^%^MAGENTA%^     "+arrange_string(tmp[i],10)+"%^RESET%^%^CYAN%^:%^RESET%^%^GREEN%^  "+map[tmp[i]]+"%^RESET%^");
    }

    tell_object(TP,"%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
    return 1;
}

void init()
{
    ::init();
    add_action("add_token","add");
    add_action("set_tokens","set");
    add_action("show_tokens","tokens");
    add_action("showtokens","showtokens");
    add_action("read_box","read");
    add_action("exchange_tokens","exchange");
    add_action("exchange_tokens","give");
    add_action("produce_token","produce");
    return;
}

int isMagic() { return 1; }
