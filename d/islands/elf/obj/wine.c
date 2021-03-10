//code stolen from crystal's antioch wine
#include <std.h>
#include "../elf.h"
inherit OBJECT;

int drinks;

void create()
{
        ::create();
        set_name("bottle");
        set_short("A bottle of elven wine");
        set_id(({"bottle","wine","elven wine","drink","bottle of wine"}));
        set_long(
        "%^CYAN%^This is a finely crafted bottle of elven wine.  It comes"+
		" in a bottle etched with %^GREEN%^leaf patterns%^CYAN%^.  The bottle is "+
		"wrapped in dried leaves that retain a %^BOLD%^%^GREEN%^bright green%^RESET%^%^CYAN%^ color."+
		"  The smell of the wine is light and sweet.  "+
		"The wine is colored a %^MAGENTA%^pink hew.%^RESET%^" 
        );
        set_weight(4);
        set_value(400);
        drinks = 4;
}

void init()
{
        ::init();
        add_action("drink","drink");
}

void drink(string str)
{
     if(!living(ETO)) {
       notify_fail("You must be holding the wine bottle to be able to drink from it.\n");
                return 0;
        }
     if(!interactive(ETO)) {
             notify_fail("You must be holding the wine bottle to be able to drink from it.\n");
              return 0;
        }
     if(str == "from bottle" || str == "from wine bottle" || str == "wine") {
                if(drinks < 1) {
                        notify_fail("Drink from what?  From bottle?.\n");
                        return 0;
                }
             if(!ETO->add_intox(175)) {
                        notify_fail("You can't stand to drink anymore!\n");
                        return 0;
                }
              if(drinks > 1) {
                        tell_object(ETO,"You take a long gulp from the wine bottle, the"+
                        " warm, sweet liquid slides down your throat.");
                        tell_room(environment(ETO),""+ETO->query_cap_name()+" takes a"+
                        " long gulp from the wine bottle.",ETO);
                  
                        drinks -= 1;
                        return 1;
                }
              if(drinks == 1) {
                        tell_object(ETO,"You take the last gulp from the bottle, the"+
                        " warm, sweet liquid slides down your throat.");
                        tell_room(environment(ETO),""+ETO->query_cap_name()+" drinks the"+
                        " last of the wine from the bottle.",ETO);
                    
                        drinks -= 1;
                        TO->set_long("This is an empty bottle of wine.");
                        TO->set_short("An empty bottle of wine");
              TO->set_id(({"empty bottle","bottle","empty bottle of wine","empty wine bottle"}));
                        TO->set_weight(1);
                        TO->set_value(1);
                        return 1;
                }
        }
}
