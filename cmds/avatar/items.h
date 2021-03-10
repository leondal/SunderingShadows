// fixing the wield/wear/unwield/unwear to use ETO not TP so they won't bug on forced actions
// *Styx* (having been taught to recognize the problem by Garrett)  5/12/03
//adding checks for valid targ and ETO on hit to help with stab bugs Circe 1/10/05

#define HEADER(x) "#include <std.h>\ninherit "+x+";\n\nvoid create(){\n\t::create();\n"
#define HEADER2(x) "#include <std.h>\ninherit \""+x+"\";\n\nvoid create(){\n\t::create();\n"
#define WEAPHEAD(x) "#include <std.h>\ninherit \"/d/common/obj/weapon/"+x+"\";\n\nvoid create(){\n\t::create();\n"
#define NAME(x) "\tset_name(\""+x+"\");\n"
#define ID(x) "\tset_id("+x+");\n"
#define ADDID(x) "\tadd_id("+x+");\n"
#define OBVIOUS_SHORT(x) "\tset_obvious_short(\""+x+"\");\n"
#define SHORT(x) "\tset_short(\""+x+"\");\n"
#define LONG(x) "\tset_long(\n@AVATAR\n"+x+"\nAVATAR\n\t);\n"
#define WEIGHT(x) "\tset_weight("+x+");\n"
#define VALUE(x) "\tset_value("+atoi(x)+");\n"
#define READ(x) "\tset(\"read\",\n@AVATAR\n"+x+"\nAVATAR\n\t);\n"
#define LORE(x) "\tset_lore(\n@AVATAR\n"+x+"\nAVATAR\n\t);\n"
//#define LOREDIFF(x) "\tset_property("lore difficulty","+x+");\n"
#define PROP(x,y) "\tset_property(\""+x+"\","+y+");\n"
#define CLOSE "}\n"
#define HEART_BEAT "\tset_heart_beat(1);\n"

//armor
#define MAX_ENC(x) "\tset_max_internal_encumbrance("+x+");\n"
#define AC(x) "\tset_ac("+atoi(x)+");\n"
#define ENCHANTMENT(x) "\tset_property(\"enchantment\","+atoi(x)+");\n"
#define LIMBS(x) "\tset_limbs("+x+");\n"
#define TYPE(x) "\tset_type(\""+x+"\");\n"
#define STRUCK "\tset_struck((:TO,\"strike_func\":));\n"
#define WEAR "\tset_wear((:TO,\"wear_func\":));\n"
#define UNWEAR "\tset_remove((:TO,\"remove_func\":));\n"
#define SIZE(x) "\tset_size("+x+");\n"

//weapons
#define LARGE_WC(x,y) "\tset_large_wc("+x+","+y+");\n"
#define WC(x,y) "\tset_wc("+x+","+y+");\n"
#define PROF_TYPE(x) "\tset_prof_type(\""+x+"\");\n"
#define WIELD "\tset_wield((:TO,\"wield_func\":));\n"
#define UNWIELD "\tset_unwield((:TO,\"unwield_func\":));\n"
#define HIT "\tset_hit((:TO,\"hit_func\":));\n"

//For use with the adding heart_beat emotes
//to items - Saide

#define TEMP(x) read_file("/d/avatars/"+x+"/temp.heartbeat")
#define TEMP_REMOVE(x) rm("/d/avatars/"+x+"/temp.heartbeat")
#define TEMP_HEADER "\nvoid heart_beat()\n{\n\t if(!objectp(TO)) { return; }\n\t if(!objectp(ETO)) { return; }\n\t if(TO->is_weapon()) \n\t { \n\t\tif(!TO->query_wielded()) { return; } \n\t } \n\t if(TO->is_armor())\n\t { \n\t\tif(!TO->query_worn()) { return; } \n\t } \n\t if(!interactive(ETO)) { return; } \n\t if(random(1000) > 998) \n\t {"

#define TEMP_SWITCH(x) "\n\t\tswitch(random("+to_int(x)+")) \n\t\t{"
#define TEMP_CASE(x)   "\n\t\t\tcase "+to_int(x)+":"
#define TEMP_IP_EMOTE(x) "\n\t\t\t\ttell_object(ETO, \""+x+"\");"
#define TEMP_ROOM_EMOTE(x) "\n\t\t\t\ttell_room(EETO, \""+x+"\", ({ETO}));"
#define TEMP_CASE_CLOSE "\n\t\t\t\tbreak;"
#define TEMP_SWITCH_CLOSE "\n\t\t}"
#define TEMP_HEADER_CLOSE "\n\t\}"
#define TEMP_CLOSE "\n}"

//funcs
#define WIELD_FUNC "int wield_func(){\n"
#define UNWIELD_FUNC "int unwield_func(){\n"
#define WEAR_FUNC "int wear_func(){\n"
#define REMOVE_FUNC "int remove_func(){\n"

#define HIT_FUNC "int hit_func(object targ){\n\tif(!objectp(targ)) return 0;\n\tif(!objectp(ETO)) return 0;\n"
#define LANCE_HIT_FUNC "int hit_func(object targ){\n\t::check(targ);\n\tif(!objectp(targ)) return 0;\n\tif(!objectp(ETO)) return 0;\n"
#define STRUCK_FUNC "int strike_func(int damage, object what, object who){\n"

#define DO_MESSAGE_BLOCK(x,y) "\ttell_room(environment(ETO),\""+x+"\",ETO);\n\ttell_object(ETO,\""+y+"\");\n"
#define UNDO_MESSAGE_BLOCK(x,y) "\ttell_room(environment(ETO),\""+x+"\",ETO);\n\ttell_object(ETO,\""+y+"\");\n"

#define HIT_MESSAGE_BLOCK(x,y,z) "\ttell_room(environment(query_wielded()),\""+x+"\",({ETO,targ}));\n\ttell_object(ETO,\""+z+"\");\n\ttell_object(targ,\""+y+"\");\n"
#define STRUCK_MESSAGE_BLOCK(x,y,z) "\ttell_room(environment(query_worn()),\""+x+"\",({ETO,who}));\n\ttell_object(ETO,\""+z+"\");\n\ttell_object(who,\""+y+"\");\n"


#define VALID_TYPES (["object":"OBJECT","armor":"ARMOUR","pocketarmor":"PARMOUR","weapon":"WEAPON"])
#define WF(x) write_file(FILE,x)
#define TEMP_WRITE(x, y) write_file("/d/avatars/"+x+"/temp.heartbeat", y)
