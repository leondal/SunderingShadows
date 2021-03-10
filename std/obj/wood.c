//wood.c

#include <std.h>
#include <materials.h>

inherit MATERIAL;

string woodType;

// set_wood_type(), set_wood_quality(), and set_wood_quantity() added by 
// Ares on 9/13/04 to allow for changing of wood after creation

void set_wood_type(string type)
{
    if(member_array(type,WOOD_TYPES) == -1) { write("Invalid wood type."); return; }
    TO->set_subtype(type);
    
    TO->set_name(query_subtype()+" wood");
    TO->set_id(({"block",query_subtype(),"wood"}));
    TO->set_short("A block of "+query_subtype());
    TO->set_long("This is a block of "+query_quality()+" "+query_subtype()+".");
}

void set_wood_quality(int quality)
{
    if(quality < 1 || quality > 10) { write("You must enter a number between 1 and 10 for quality"); return; }
    TO->set_quality_type(quality);
    TO->set_long("This is a block of "+query_quality()+" "+query_subtype()+".");
    return;
}

void set_wood_quantity(int quantity)
{
    if(quantity < 1) { write("You must enter a number greater than 0 for quantity"); return; }
    TO->set_uses(quantity);
    return;
}


void create(){
    ::create();
    set_type("wood");
    woodType = WOOD_TYPES[random(sizeof(WOOD_TYPES))];
    set_subtype(woodType);
    set_quality_type(random(10)+1);
    set_uses(random(3)+1);
    set_name(woodType+" wood");
    set_id(({"block",woodType,"wood"}));
    set_short("A block of "+query_subtype());
    set_long("This is a block of "+query_quality()+" "+query_subtype()+".");
    set_weight(8);
    set_cointype("gold");
    set_property("treasure_type", "5C");
}

int query_value(){
   switch(query_subtype()) {
   	case "pine": case "poplar": case "birch": case "cedar": case "beech":
			return query_uses()*query_quality_type()*5;
	case "white ash": case "oak": case "hickory": case "hazelnut": case "willow": case "spruce":
			return query_uses()*query_quality_type()*7;
    	case "chestnut": case "cherry": case "elm": case "maple": case "blueleaf": case "cypress":
			return query_uses()*query_quality_type()*10;
    	case "rosewood": case "redwood": case "mahogony": case "walnut": case "duskwood": case "silverbark":
			return query_uses()*query_quality_type()*13;
     	case "butternut": case "teak": case "boxwood": case "alder": case "ebony": case "shadowtop":
			return query_uses()*query_quality_type()*15;
	default:
			return query_uses()*query_quality_type()*5;
 	}
}
