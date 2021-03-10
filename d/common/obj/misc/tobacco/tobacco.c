// New tobacco inherit. Nienne, 02/08.
#include <std.h>
inherit OBJECT;

int loads, sp, min_con, hasmsgs, intox;
string* mymsgs, * yourmsgs;

void create()
{
    ::create();
    set_id(({ "tobacco" }));
    set_name("tobacco");
    set_short("A pouch of tobacco");
    set_long("This is a pouch of standard tobacco.  The leaves are finely chopped and ready to be smoked in a "
             "pipe.\n%^YELLOW%^You should pack this in a pipe.\n%^RESET%^There are " + loads + " loads left.");
    set_weight(1);
    set_value(100);
    loads = 50;
    hasmsgs = 0;
}

int use_load()
{
    loads -= 1;
    if (living(ETO)) {
        tell_room(EETO, "%^BOLD%^%^BLACK%^The smoky scent of the tobacco wafts into the air.");
    }
    if (loads < 1) {
        write("%^BOLD%^%^BLACK%^Your pouch of tobacco is empty, so you discard it!");
        remove();
    }
    set_long("This is a pouch of standard tobacco.  The leaves are finely chopped and ready to be smoked in a "
             "pipe.\n%^YELLOW%^You should pack this in a pipe.\n%^RESET%^There are " + loads + " loads left.");
    return sp;
}

int query_uses()
{
    return loads;
}

void set_uses(int myuses)
{
    loads = myuses;
}

int query_con_check()
{
    return min_con;
}

void set_con_check(int mycon)
{
    min_con = mycon;
}

int query_has_messages()
{
    return hasmsgs;
}

void set_has_messages()
{
    hasmsgs = 1;
}

void set_my_messages(string* themsgs)
{
    mymsgs = themsgs;
}

void set_your_messages(string* themsgs)
{
    yourmsgs = themsgs;
}

string* query_my_messages()
{
    return mymsgs;
}

string* query_your_messages()
{
    return yourmsgs;
}

int is_tobacco()
{
    return 1;
}

void set_intox(int myintox)
{
    intox = myintox;
}

int query_intox()
{
    return intox;
}
