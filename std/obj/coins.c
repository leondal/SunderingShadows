//	/obj/coins.c
//	from the Nightmare mudlib
//	object for freely occurring money
//	created by Descartes of Borg september 1992

inherit "/std/Object";
inherit "/std/money";

void init() {
    string *currs;
    int tmp_size, i;
    object tmp;

    if(!(tmp = environment(this_object()))) return;
    if(!living(tmp)) return;
    for(i=0, tmp_size = sizeof(currs=query_currencies()); i<tmp_size; i++) {
        tmp->add_money(currs[i], query_money(currs[i]));
        set_money(currs[i], 0);
    }
    call_out("remove", 2);
}

void create() {
    set("id", ({"pile", "pile of coins", "coins", "money" }) );
    set_name("money");
     set_property("no animate",1);
    set_short("A pile of coins");
}

string query_long(string str) {
    string *currs;
    int i, tmp;
    string desc;

    desc = "A pile of ";
    for(i=0, tmp=sizeof(currs=query_currencies()); i<tmp; i++) {
        if(query_money(currs[i])) desc += query_money(currs[i])+
          " "+currs[i]+"\n";
    }
    return desc;
}
