inherit "/d/darkwood/tabor/mon/guard.c";


void create()
{
    ::create();   
}

void init()
{
    ::init();


    if(!userp(TP)){

        return;
    }

    if (TP->query_invis()) {
        return;
    }

   if (query_bad_race(TP)) {
        return;
    }
 
   if(TP->query_level() > 9) {
        return;
    }

    call_out("notify_newcomers", 1);
}

void notify_newcomers()
{
    command("say Hello traveller. If you plan to journey outside of town, I suggest you visit the scribe first for a free %^BOLD%^%^ORANGE%^map%^RESET%^ of the area.");
}