//cloth.c
// revoked color options on cloth; this can be added by players when crafting. N, 9/12.
#include <std.h>
#include <materials.h>

inherit MATERIAL;

string clothType;

// set_cloth_type_and_color(), set_cloth_quality() and set_cloth_quantity() added
// 9/11/04 by Ares to allow for adjustment of cloth after creation

void set_cloth_type_and_color(string type, string color)
{
    if(type && member_array(lower_case(type), CLOTH_TYPES) == -1) { write("Invalid cloth type.\n"); return; }
    if(!type) { type = CLOTH_TYPES[random(sizeof(CLOTH_TYPES))]; }
    
    TO->set_subtype(lower_case(type));

/*    if(color && member_array(lower_case(color), CLOTH_COLORS[query_subtype()]) == -1)
    {
        write("Invalid color for cloth type "+query_subtype()+".\n");
        return;
    }
    if(!color) { color = CLOTH_COLORS[query_subtype()][random(sizeof(CLOTH_COLORS[query_subtype()]))]; }
    
    TO->set_color(color); */
    TO->set_color("natural");

    TO->set_name(query_subtype()+" cloth");
    TO->set_id(({"bolt",query_subtype(),"cloth"}));
    TO->set_short("Some natural "+query_subtype());
    TO->set_long("This is a bolt of "+query_quality()+" "+query_subtype()+". It has been left in its natural state, unmarked by dye.");
    return;
}

void set_cloth_quality(int quality)
{
    if(quality < 1 || quality > 10) { error("You must enter a number between 1 and 10 for quality"); return; } 
    TO->set_quality_type(quality);
    TO->set_long("This is a bolt of "+query_quality()+" "+query_color()+" "+query_subtype()+".");
    return;
}

void set_cloth_quantity(int quantity)
{
    if(quantity < 1) { error("You must enter a number greater than 0 for quantity"); return; }
    TO->set_uses(quantity);
    return;
}


void create(){
    ::create();
    set_type("cloth");

    clothType = CLOTH_TYPES[random(sizeof(CLOTH_TYPES))];
//    set_color(CLOTH_COLORS[clothType][random(sizeof(CLOTH_COLORS[clothType]))]);
    set_color("natural");
    set_subtype(clothType);
    set_quality_type(random(10)+1);
    set_uses(random(10)+3);
    set_name(clothType+" cloth");
    set_id(({"bolt",clothType,"cloth"}));
    set_short("Some natural "+query_subtype());
    set_long("This is a bolt of "+query_quality()+" "+query_subtype()+". It has been left in its natural state, unmarked by dye.");
    set_weight(5);
    set_cointype("gold");
    set_property("treasure_type", "5C");
}

int query_value() {
/*   switch(query_subtype()) {
   	case "burlap":  
	case "homespun":
		return query_uses()*query_quality_type()*2;
	case "muslin":
        case "gauze":
 		return query_uses()*query_quality_type()*3;
	case "felt":	
	case "flannel":    
	case "broadcloth":
        case "hemp":
 		return query_uses()*query_quality_type()*4;
	case "crepe":   
	case "wool":	
	case "cotton":
 		return query_uses()*query_quality_type()*5;
	case "linen":
	case "tweed":	
	case "chiffon":
 		return query_uses()*query_quality_type()*6;
    	case "suede":	
	case "lace":
		return query_uses()*query_quality_type()*7;
     	case "silk":
		return query_uses()*query_quality_type()*9;
     	case "satin":
     	case "velvet":
        case "taffeta":
		return query_uses()*query_quality_type()*10;
     	case "brocade":
        case "lame":
		return query_uses()*query_quality_type()*11;
	default:
		return query_uses()*query_quality_type()*5;
   }*/
   return (query_uses()*query_quality_type()*5)+roll_dice(2,4); // put back to a default setting with slight random element
}

