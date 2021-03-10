#include <std.h>

inherit ARMOUR;

#define FURS ({"%^BOLD%^%^BLACK%^jaguar",\
"%^YELLOW%^lion",\
"%^BOLD%^%^WHITE%^winter wolf",\
"%^BOLD%^%^BLACK%^wolf",\
"%^RESET%^%^ORANGE%^mink",\
"%^RESET%^%^ORANGE%^l%^YELLOW%^e%^RESET%^%^ORANGE%^o%^YELLOW%^p%^RESET%^%^ORANGE%^a%^YELLOW%^r%^RESET%^%^ORANGE%^d"})

#define COLORS ({"%^BOLD%^%^BLACK%^black",\
"%^BOLD%^%^WHITE%^white",\
"%^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^a%^RESET%^y",\
"%^RESET%^%^ORANGE%^brown"})

string FUR, COLOR;

void create(){
    ::create();
    FUR = FURS[random(sizeof(FURS))];
    COLOR = COLORS[random(sizeof(COLORS))];
    set_name("fur coat");
    set_id(({"fur coat","coat","Fur Coat",""+FUR+" Coat"}));
    set_short("A fine "+FUR+"-trimmed coat");
    set_long("Made from a soft "+COLOR+" material %^RESET%^and lined with "+
       "matching silk, this coat is the very height of fashion "+
       "among the wealthy.  It features two square pockets in the "+
       "front as well as a row of buttons made of matching "+COLOR+" "+
       "gemstones%^RESET%^.  Adding even further ornamentation to "+
       "this coat is the elegant collar made of the fur of a "+FUR+" "+
       "%^RESET%^and the coordinating thin "+FUR+"-fur border %^RESET%^atop "+
       "each of the pockets.");
    set_lore("Coveted by the poor, these fur coats are worn by the "+
       "wealthy in Seneca.  Most of the affluent have a coat in each "+
       "fur available, and some have more than one of each kind.  "+
       "These coats are worn over eveningwear when the weather "+
       "turns the slightest bit chilly.");
    set_property("lore difficulty",10);
    set_weight(2);
    set_type("clothing");
    set_limbs(({"neck"}));
    set_value(500+random(151));
    switch(random(7)){
       case 0..1: set_size(1);
               break;
       case 2: set_size(3);
               break;
       default: set_size(2);
                break;
   }
}
