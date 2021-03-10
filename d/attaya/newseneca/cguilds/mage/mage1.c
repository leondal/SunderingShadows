#include <std.h>

inherit VAULT;

void create()
{
    ::create();
set_property("indoors",1);
set_property("light",2);
    set_short("%^ORANGE%^Soulman's Funery and Death Emporium.%^RESET%^");
set_long(
@MAGE
%^ORANGE%^Soulman's Funery and Death Emporium.%^RESET%^
All around you, you see coffins of various sizes, made from various kinds of wood. The lighting is dim and soft to the senses. There are many serves one can acquire here including: an assortment of different funery rites, coffin types, and other assorted extras one might desire when planning a funeral. (Either one's own or that of another.) Mr. Soulman will attend to your wishes as best he can, considering his limited physical capabilities.
%^ORANGE%^Welcome and enjoy your stay.%^RESET%^
MAGE
);
    set_light(2);
    set_indoors(0);
    set_smell("default","You smell new wood, varnish, and Death here. ");
    set_listen("default","The bustle of the city can vaguely be heard through the walls.");
    set_items( ([
"coffin" : "As you look at the coffin you see strange writing on the side.",
"writing" : "%^BOLD%^%^RED%^The writing reads:%^RESET%^ Only those of special ability may enter here!",
    ]) );
    set_exits( ([
"coffin" : "/d/attaya/seneca/town/cguilds/mage/mage2.c",
"out" : "/d/attaya/seneca/town/yard33.c",
    ]) );
        set_door("door", "/d/attaya/seneca/town/yard33",
"out", 0);
      set_open("door", 0); 
    set_invis_exits( ({"coffin"}) );
    set_pre_exit_functions( ({"coffin"}),
         ({"allow"}) );
}

int allow()
{
if((!TP->is_class("mage")) && (!TP->is_class("bard")))
    {
write("%^YELLOW%^As you enter the coffin, your body begins to feel numb.\nYou breathe in deep gasps, and flee the coffin! ");
say("%^YELLOW%^ "+TPQCN+" enters the coffin then quickly jumps out, gasping for breath.\n"+TP->query_subjective()+" barely survives being trapped inside the coffin. ");
        return 0;
    }
tell_room(TO,TP->query_cap_name()+" confidently enters the coffin.",TP);

    return 1;
}
void reset(){
  ::reset();

if(!present("soulman"))
  new("/d/attaya/seneca/cguilds/mage/soul.c")->move(TO);
}
