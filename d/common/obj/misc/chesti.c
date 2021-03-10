#include <std.h>
#include <materials.h>
inherit "/std/bag_logic";

#define VALID_COLORS ({"%^RED%^", "%^GREEN%^", "%^ORANGE%^", "%^CYAN%^", "%^BLUE%^", "%^MAGENTA%^", "%^YELLOW%^", "%^WHITE%^"})

#define CH_DESIGNS ({"rough", "simple", "ornate", "rotting"})

#define CH_SPEC_TYPES ({"ice", "fire", "mimic", "shadow"})

#define CH_SIZES ({"tiny", "small", "medium", "large", "huge"})

string chest_type = "normal";
int charges;

void create()
{
    ::create();
    set_no_clean(1);
    set_possible_to_close(1);
    set_closed(1);
    set_property("repairtype",({ "woodwork" }));
}


void create_treasure_chest(mixed size, string type)
{
    string cmtype, hmtype, ccolor, scolor, dtype;
    int x = 0;
	//cmtype variable is the material type
	//of the chest, weight is slightly more if it's metal.
	//hmtype variable is the material type
	//of the hinges - either wood or metal.
	//ccolor variable is the color of the description of
	//chest
	//scolor variable is the color of the short
	//description of the chest
	//dtype variable is the design type of
	//the chest - ornate, simple, rough, rotten, etc.

	//Type is either lockable or not
	//Size is the size of the chest
	//can be tiny, small, medium, large,
	//or huge. Can be in the format
	//1 || tiny, 2 || small,
	//3 || medium, 4 || large,
	//5 || huge.

    if (query_property("created") || query_property("restoring")) return;

    if(!random(2))
    {
        cmtype = METAL_TYPES[random(sizeof(METAL_TYPES))];
        x = 1;
    }
    else {  cmtype = WOOD_TYPES[random(sizeof(WOOD_TYPES))]; }
	if(!random(2)) { hmtype = METAL_TYPES[random(sizeof(METAL_TYPES))]; }
	else { hmtype = WOOD_TYPES[random(sizeof(WOOD_TYPES))]; }
    ccolor = VALID_COLORS[random(sizeof(VALID_COLORS))];
    scolor = VALID_COLORS[random(sizeof(VALID_COLORS))];
    dtype = CH_DESIGNS[random(sizeof(CH_DESIGNS))];
    if(type == "random")
    {
        switch(random(2))
        {
            case 0:
                type = "lockable";
                break;
            case 1:
                type = 0;
                break;
        }
    }
    if(!size || size == "random") size = random(5) + 1;
    if(size == 1 || size == "tiny")
    {
        TO->set_value(10);
        TO->set_weight(5);
        if(x) { TO->set_weight(9); }
        size = "tiny";
        TO->set_max_internal_encumbrance(10);
    }
    if(size == 2 || size == "small")
    {
        TO->set_value(75);
        TO->set_weight(7);
        if(x) TO->set_weight(11);
        size = "small";
        TO->set_max_internal_encumbrance(30);
    }
    if(size == 3 || size == "medium")
    {
        TO->set_value(150);
        TO->set_weight(15);
        if(x) TO->set_weight(20);
        size = "medium";
        TO->set_max_internal_encumbrance(45);
    }
    if(size == 4 || size == "large")
    {
        TO->set_value(300);
        TO->set_weight(30);
        if(x) TO->set_weight(40);
        size = "large";
        TO->set_max_internal_encumbrance(80);
    }
    if(size == 5 || size == "huge")
    {
        TO->set_value(1000);
        TO->set_weight(75);
        if(x) TO->set_weight(100);
        size = "huge";
        TO->set_max_internal_encumbrance(250);
    }
    if(type == "lockable")
    {
        TO->set_lock("locked");
        TO->set_key("chest");
    }
    if(type)
    {
        TO->set_short(scolor+"A "+size+ " " +type+ " "+
        VALID_COLORS[random(sizeof(VALID_COLORS))] +
        cmtype + scolor + " chest with " +
        VALID_COLORS[random(sizeof(VALID_COLORS))] +
        hmtype + " hinges");

        switch(dtype)
        {
            case "rough":
                TO->set_open_long(ccolor+ "This rough, "+size+
                " chest, has been hastily carved from " +
                VALID_COLORS[random(sizeof(VALID_COLORS))] +
                cmtype+"%^RESET%^"+
                ccolor+".  Its creation was careless "+
                "and quick, offering a storage area "+
                "without any concern for durability.  "+
                "It has been fitted with a lock and "+
                VALID_COLORS[random(sizeof(VALID_COLORS))] +
                hmtype+"%^RESET%^"+
                ccolor+" hinges in order for it to open and "+
                "close.%^RESET%^");
                break;


            case "simple":
                TO->set_open_long(ccolor+ "This simple, "+size+
                " chest, has been carved from " +
                VALID_COLORS[random(sizeof(VALID_COLORS))] +
                cmtype+"%^RESET%^"+
                ccolor+".  Its design is one of simplicity "+
                "and convenience, offering a storage area "+
                "without any concern for its appearance.  "+
                "It has been fitted with a lock and "+
                VALID_COLORS[random(sizeof(VALID_COLORS))] +
                hmtype+"%^RESET%^"+
                ccolor+" hinges in order for it to open and "+
                "close properly.%^RESET%^");
                break;

            case "ornate":

                TO->set_open_long(ccolor+ "This ornate, "+size+
                " chest, has been expertly carved from " +
                VALID_COLORS[random(sizeof(VALID_COLORS))] +
                cmtype+"%^RESET%^"+ccolor+
                ".  Its creation was one of "+
                "great pain and effort, resulting in "+
                "the ornate work of art that you now see "+
                "before you.  It is covered with strange "+
                "and mysterious patterns that serve only to "+
                "add to its overall beauty.  It serves, not "+
                "only as a storage area, but a durable "+
                "piece of art.  It has been fitted with a lock "+
                "and brilliant "+
                VALID_COLORS[random(sizeof(VALID_COLORS))] +
                hmtype+"%^RESET%^"+
                ccolor+" hinges in order for it to open and "+
                "close silenty.%^RESET%^");
                break;

            case "rotting":
                TO->set_open_long(ccolor+ "This rotting, "+size+
                " chest, has been carved from " +
                VALID_COLORS[random(sizeof(VALID_COLORS))] +
                cmtype+"%^RESET%^"+
                ccolor+".  Its original design has "+
                "been lost in time and weathered away "+
                "by nature.  It offers a storage area, but "+
                "has no concern for durability.  "+
                "It has been fitted with a lock and "+
                VALID_COLORS[random(sizeof(VALID_COLORS))] +
                hmtype+"%^RESET%^"+
                ccolor+" hinges, hopefully it "+
                "might still open and close.%^RESET%^");
                break;
            }
    }
    else
    {
        TO->set_short(scolor+"A "+size+ " " +
        VALID_COLORS[random(sizeof(VALID_COLORS))] +
        cmtype + scolor + " chest with " +
        VALID_COLORS[random(sizeof(VALID_COLORS))] +
        hmtype + " hinges");

        switch(dtype)
        {
            case "rough":
                TO->set_open_long(ccolor+ "This rough, "+size+
                " chest, has been hastily carved from " +
                VALID_COLORS[random(sizeof(VALID_COLORS))] +
                cmtype+ccolor+".  Its creation was careless "+
                "and quick, offering a storage area "+
                "without any concern for durability.  "+
                "It has been fitted with "+
                VALID_COLORS[random(sizeof(VALID_COLORS))] +
                hmtype+ccolor+" hinges in order for it to open and "+
                "close.%^RESET%^");
                break;

            case "simple":
                TO->set_open_long(ccolor+ "This simple, "+size+
                " chest, has been carved from " +
                VALID_COLORS[random(sizeof(VALID_COLORS))] +
                cmtype+ccolor+".  Its design is one of simplicity "+
                "and convenience, offering a storage area "+
                "without any concern for its appearance.  "+
                "It has been fitted with "+
                VALID_COLORS[random(sizeof(VALID_COLORS))] +
                hmtype+ccolor+" hinges in order for it to open and "+
                "close properly.%^RESET%^");
                break;

            case "ornate":

                TO->set_open_long(ccolor+ "This ornate, "+size+
                " chest, has been expertly carved from " +
                VALID_COLORS[random(sizeof(VALID_COLORS))] +
                cmtype+ccolor+".  Its creation was one of "+
                "great pain and effort, resulting in "+
                "the ornate work of art that you now see "+
                "before you.  It is covered with strange "+
                "and mysterious patterns that serve only to "+
                "add to its overall beauty.  It serves, not "+
                "only as a storage area, but a durable "+
                "piece of art.  It has been fitted with equally "+
                "brilliant "+
                VALID_COLORS[random(sizeof(VALID_COLORS))] +
                hmtype+ccolor+" hinges in order for it to open and "+
                "close silenty.%^RESET%^");
                break;

            case "rotting":
                TO->set_open_long(ccolor+ "This rotting, "+size+
                " chest, has been carved from " +
                VALID_COLORS[random(sizeof(VALID_COLORS))] +
                cmtype+ccolor+".  Its original design has "+
                "been lost in time and weathered away "+
                "by nature.  It offers a storage area, but "+
                "has no concern for durability.  "+
                "It has been fitted with "+
                VALID_COLORS[random(sizeof(VALID_COLORS))] +
                hmtype+ccolor+" hinges, hopefully it "+
                "might still open and close.%^RESET%^");
                break;
        }
    }
    TO->set_id(({"chest", cmtype+" chest", size+" chest"}));
    TO->set_name("chest");
    TO->set_closed_long(TO->query_open_long_desc() + "\n"+
    "%^BOLD%^%^WHITE%^It is currently closed.%^RESET%^");
    TO->set_open_long(TO->query_open_long_desc() + "\n"+
    "%^BOLD%^%^WHITE%^It is currently open.%^RESET%^");
    TO->set_long(TO->query_closed_long_desc());
    set_property("created",1);
}

void make_speciality_chest(string ctype, mixed size, string type)
{
    if(!ctype || ctype == "random") ctype = CH_SPEC_TYPES[random(sizeof(CH_SPEC_TYPES))];
	if(member_array(ctype, CH_SPEC_TYPES) == -1)  { TO->remove(); return; }

    if(!size || size == "random") { size = CH_SIZES[random(sizeof(CH_SIZES))]; }

    if(intp(size))
    {
        if(to_int(size-1) <= sizeof(CH_SIZES))
        {
            size = CH_SIZES[size-1];
        }
    }

    if(type == "random")
    {
        switch(random(2))
        {
            case 0:
                type = "lockable";
                break;
            case 1:
                type = 0;
                break;
        }
    }
    TO->create_treasure_chest(size, type);
    chest_type = ctype;
    if(ctype == "fire")
    {
        charges = 10 + random(11);
        if(type)
        {
            TO->set_short("%^BOLD%^%^RED%^A "+size+" "+type+
            " flaming chest%^RESET%^");
            TO->set_open_long("%^BOLD%^%^RED%^This "+size+
            " chest is made from an eternally burning flame, "+
            "that by some magic method, has been shaped and "+
            "manipulated to serve as a storage space.  However, "+
            "the fire which is the chest, makes it dangerous "+
            "to carry and probably unwise to use.  "+
            "A deep tunnel of flame in the front of the lid serves "+
            "as the lock, forcing whoever might be "+
            "unlucky enough to carry it to first unlock it.%^RESET%^");
        }
        else
        {
            TO->set_short("%^BOLD%^%^RED%^A "+size+" "+type+
            " flaming chest%^RESET%^");
            TO->set_open_long("%^BOLD%^%^RED%^This "+size+
            " chest is made from an eternally burning flame, "+
            "that by some magic method, has been shaped and "+
            "manipulated to serve as a storage space.  However, "+
            "the fire which is the chest, makes it dangerous "+
            "to carry and probably unwise to use.  "+
            "Thankfully there is no visible part that "+
            "serves as a lock and therefore it might "+
            "be quick and relatively painless to open.%^RESET%^");
        }
    }
    TO->set_id(({"chest", ctype+" chest", size+" chest"}));
    TO->set_name("chest");
    TO->set_closed_long(TO->query_open_long_desc() + "\n"+
    "%^BOLD%^%^WHITE%^It is currently closed.%^RESET%^");
    TO->set_open_long(TO->query_open_long_desc() + "\n"+
    "%^BOLD%^%^WHITE%^It is currently open.%^RESET%^");
    TO->set_long(TO->query_closed_long_desc());

    if(ctype != "shadow")
    {
        set_heart_beat(5);
    }
}

void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(chest_type == "fire")
    {
        if(objectp(EETO) && interactive(EETO))
        {
            if(ETO->is_container())
            {
                tell_object(EETO, "%^RED%^Your "+
                ETO->query_cap_name() + " is slowly burning!!"+
                "%^RESET%^");

                tell_room(environment(EETO), EETO->query_cap_name()+
                "%^RED%^'s "+ETO->query_cap_name()+ " is slowly "+
                "burning!!%^RESET%^", ({EETO}));
                charges--;
                if(charges <= 0)
                {
                    tell_object(EETO, "%^RED%^Your "+
                    ETO->query_cap_name() + " erupts into flame "+
                    "and all of its inventory burns away!%^RESET%^");

                    tell_room(environment(EETO),
                    ETO->query_cap_name() +
                    "%^RED%^'s "+ETO->query_cap_name() +
                    " erupts into flame and "+
                    "all of its inventory burns away!%^RESET%^",
                    ({EETO}));
                    if(!interactive(ETO)) ETO->remove();
                    TO->remove();
                }

            }
        }
        if(objectp(ETO) && interactive(ETO))
        {
            tell_object(ETO, "%^RED%^The chest continues to "+
            "flare, burning you!%^RESET%^");
            tell_room(EETO, ETO->query_cap_name() + "%^RED%^" +
            "'s flaming chest, continues to flare, burning "+
            ETO->query_objective() + "!%^RESET%^", ({ETO}));
            charges--;
            ETO->do_damage("torso", roll_dice(2, 6));
            if(charges <= 0)
            {
                tell_object(ETO, "%^RED%^Your flaming chest "+
                "explodes into "+
                "a puff of ash and all of its inventory along with "+
                "it!%^RESET%^");
                tell_room(EETO, ETO->query_cap_name() +"%^RED%^'s "+
                "flaming chest explodes into a puff of ash and all "+
                "of its inventory burns away!%^RESET%^", ({ETO}));
                TO->remove();
            }
        }
    }
}

int restore_me(string file) {
    int hold;
    set_property("restoring",1);
    set_max_internal_encumbrance(10000);
    hold=::restore_me(file);
    set_max_internal_encumbrance(query_property("int_enc"));
    set_weight(query_property("my_wgt"));
    remove_property("restoring");
}

int save_me(string file)
{
    int hold;
    remove_property("my_wgt");
    remove_property("int_enc");
    set_property("my_wgt",query_weight());
    set_property("int_enc",query_max_internal_encumbrance());
    set_max_internal_encumbrance(10000);
    hold = ::save_me(file);
    set_max_internal_encumbrance(query_property("int_enc"));
    return hold;
}

int is_chest() { return 1; }

int is_sack() {return 1;}
