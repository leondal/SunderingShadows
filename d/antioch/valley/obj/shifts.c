#include <std.h>
inherit "/d/common/obj/clothing/magerobe.c";

#define eletypes ({"air","water","fire","earth"})

string eletype;

void create(){
   int x;
   x = random(sizeof(eletypes));
   eletype = eletypes[x];
   ::create();
   	set_lore("Fey creature have always had a deep respect for"+
		" nature.  It is not uncommon for the fey to dress "+
		"themselves in garments and accessories that carry a "+
		"nature there.  Thus the creations of gowns and tunics"+
		" for the females and males of the fey races seems like"+
		" the logical next step.  The garments are rumored to be"+
		" woven with plenty of fey magic in them as well as "+
		"infusing each garment with its respectable element.  "+
		"There are rumors that the fey enchant each shirt with "+
            "hidden pockets, to help spread mischief.\n");
   	set_property("lore difficulty",4);
   	set_ac(0);
   	set_weight(5);
      set_max_internal_encumbrance(5);
   	set_value(200);
	set_property("enchantment",2+random(2));
   	set_type("clothing");
   	set_limbs(({"torso"}));
   	set_size(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
   	switch(eletype){
case "air":
	TO->set_long("%^BOLD%^%^BLACK%^This loose fitting shirt is made"+
		" from lightweight silk that seems to float in the air."+
                "  The stormy gray silk shirt is fitted through the chest,"+
		" and cut to drape down past the waist.  The bodice is "+
		"lightly shirred across the bust.  "+
		"Small puffed sleeves made from the "+
		"same lightweight silk is attached to the bodice of the"+
		" shirt.  The high waist shirt is finished off with a "+
		"handkerchief hem, giving it a delicate look.  A %^CYAN%^"+
		"sky blue%^BLACK%^ ribbon with %^WHITE%^w%^RESET%^h%^BOLD%^"+
		"i%^RESET%^t%^WHITE%^e %^BOLD%^%^BLACK%^and %^CYAN%^b%^BLUE%^l"+
		"%^CYAN%^u%^BLUE%^e %^BLACK%^beads is tied under the bustline of the"+
		" shirt.%^RESET%^\n");
   	TO->set_name("shirt of air");
   	TO->set_short("%^BOLD%^%^BLUE%^Shirt of %^WHITE%^A%^BLACK%^i%^WHITE%^r%^RESET%^");
   	TO->set_obvious_short("%^BOLD%^%^BLACK%^A stormy gray silk shirt%^RESET%^");
   	TO->set_id(({"shirt","blouse","shirt of air","shirt"}));
	break;
case "earth":
	TO->set_long("%^GREEN%^This tailored shirt is made from hundreds "+
		"of %^BOLD%^oak leaves%^RESET%^%^GREEN%^ made from heavy"+
		" silk. The base of this "+
		"enchanting shirt is made from dark green heavy silk, tailored "+
		"to fit close to the wearer's body.  The %^BOLD%^green%^RESET%^"+
		"%^GREEN%^ silk leaves have been appliqued all over the shirt, "+
		"overlapping each other in an elegant display of nature's bounty."+
		"  The detail on the leaves is so life like one could easily think"+
		" they were real!  The sleeveless shirt falls to the wearer's waist."+
		"%^RESET%^\n");
   	TO->set_name("shirt of earth");
   	TO->set_short("%^RESET%^%^GREEN%^Shirt of %^BOLD%^E%^RESET%^%^GREEN%^a"+
		"%^BOLD%^r%^RESET%^%^GREEN%^t%^BOLD%^h%^RESET%^");
   	TO->set_obvious_short("%^RESET%^%^GREEN%^A green heavy silk shirt%^RESET%^");
   	TO->set_id(({"shirt","blouse","shirt of earth","shirt"}));
	break;
case "fire":
	TO->set_long("%^RED%^This tailored shirt is made from %^BOLD%^fiery red"+
		"%^RESET%^%^RED%^ silk.  The fitted silk shirt is styled with a "+
		"deep V neckline and fitted sleeves that come down to the wearer's elbows."+
		"  Circular silk cuffs are attached to the sleeves, reaching"+
		" down to the wrists."+
		"  %^YELLOW%^Golden%^RESET%^%^RED%^ threads are interwoven into the "+
		"silk, giving an illusion of the shirt being on fire.  Gores of deep "+
		"%^YELLOW%^yellow%^RESET%^%^RED%^ and %^ORANGE%^orange%^RED%^ colored"+
		" silk are hidden inside the folds sleeves cuffs.  "+
		"This allows others to see bursts of fiery colors as the wearer moves,"+
		" like that of a dancing flame.%^RESET%^\n");
   	TO->set_name("shirt of fire");
   	TO->set_short("%^BOLD%^%^RED%^Shirt of %^RESET%^%^RED%^F%^BOLD%^i%^RESET%^"+
		"%^ORANGE%^r%^YELLOW%^e%^RESET%^");
   	TO->set_obvious_short("%^BOLD%^%^RED%^A fiery red silk shirt%^RESET%^");
   	TO->set_id(({"shirt","blouse","shirt of fire","shirt"}));
	break;
case "water":
	TO->set_long("%^CYAN%^This loose fitting shirt is made from medium weight "+
		"silk.  The flowing shirt has been dyed a soft sea green shade.  "+
		"The sleeveless blouse features a cowl neckline across the front and"+
		" back, giving a rippling effect to the sea green silk.  The hip "+
		"length shirt is finished off with a scalloped hemline.  %^BOLD%^%^WHITE%^"+
		"White%^RESET%^%^CYAN%^ beaded chiffon binding wraps around each "+
		"scallop, giving an illusion of foam on the surface of the sea."+
		"%^RESET%^\n");
   	TO->set_name("shirt of water");
   	TO->set_short("%^RESET%^%^CYAN%^Shirt of W%^BOLD%^%^BLUE%^a%^WHITE%^t"+
		"%^BLUE%^e%^RESET%^%^CYAN%^r%^RESET%^");
   	TO->set_obvious_short("%^RESET%^%^CYAN%^A sea green silk shirt%^RESET%^");
   	TO->set_id(({"shirt","blouse","shirt of water","shirt"}));
	break;
	}
}
int wear_func(){
// allowing men to wear these, some sound like they'd be more than fitting. N, 12/13
/*        if((string)ETO->query_gender() == "male") {
        	tell_object(ETO,"%^BOLD%^%^BLACK%^Thinking of everyone who "+
			"will laugh at you, you choose not to wear the shirt.");
        	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
        		" stops to ponder something before he tries to wear the shirt.",ETO);
		return 0;
} */
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" slides into the silk shirt.",ETO);
     	tell_object(ETO,"%^BOLD%^You slide on the silk shirt, feeling the soft "+
		"silk against your skin.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" slides off her"+
		" silk shirt slowly.",ETO);
     	tell_object(ETO,"%^BOLD%^You slide the silk shirt off slowly, "+
		"enjoying the softness of the silk.");
     	return 1;
}
