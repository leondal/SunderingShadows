//Changed to 35+ to wear, per Tsera - Octothorpe 7/16/09
#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/jewelry/circlet.c";

#define WAIT_TIME 2000
#define WAIT_TIME2 5

int used_time, used_time2, uses;
int query_uses(){return uses;}

void create(){
   ::create();
    set_short("%^BOLD%^%^WHITE%^a sl%^RESET%^e%^BOLD%^%^WHITE%^nd%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^r m%^RESET%^i%^BOLD%^%^WHITE%^th%^BOLD%^%^CYAN%^r%^BOLD%^%^WHITE%^il circlet%^RESET%^");
    set_id(({"circlet"}));
    set_name("%^BOLD%^%^WHITE%^a sl%^RESET%^e%^BOLD%^%^WHITE%^nd%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^r m%^RESET%^i%^BOLD%^%^WHITE%^th%^BOLD%^%^CYAN%^r%^BOLD%^%^WHITE%^il circlet%^RESET%^");
    set_long(
    "%^BOLD%^%^WHITE%^This circlet is a trio of %^BOLD%^%^CYAN%^b%^RESET%^r%^BOLD%^%^WHITE%^a%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^d%^RESET%^e%^BOLD%^%^CYAN%^d"+
    " %^BOLD%^%^CYAN%^m%^RESET%^i%^BOLD%^%^WHITE%^th%^BOLD%^%^CYAN%^r%^BOLD%^%^WHITE%^il bands wove to make up this diadem, the %^BOLD%^%^WHITE%^finish"+
    " %^BOLD%^%^WHITE%^of each faintly different so that the individual paths can be discerned. Though the circlet seems simple in form there is an"+
    " unmistakable %^RESET%^p%^BOLD%^%^WHITE%^r%^RESET%^e%^BOLD%^%^WHITE%^s%^RESET%^e%^BOLD%^%^WHITE%^n%^RESET%^c%^BOLD%^%^WHITE%^e about it, echoes"+
    " of greatness past. Looking at it closely, it almost seems as though it is made to mesh with two other"+
    " %^BOLD%^%^BLACK%^c%^BOLD%^%^WHITE%^i%^BOLD%^%^RED%^r%^BOLD%^%^BLACK%^c%^BOLD%^%^RED%^l%^BOLD%^%^CYAN%^e%^BOLD%^%^BLACK%^t%^BOLD%^%^WHITE%^s,"+
    " joining them.%^RESET%^");
    set_lore("%^BOLD%^%^WHITE%^This diadem was part of the crown of Earralian Silvertreen"+
             " a prince of the %^BOLD%^%^GREEN%^Sylvan elves%^BOLD%^%^WHITE%^. Rising to his"+
             " his throne in the dark times of the %^BOLD%^%^BLACK%^Crown Wars %^BOLD%^%^WHITE%^"+
             "he united the diverse %^RESET%^%^GREEN%^sylvan elf %^BOLD%^%^WHITE%^populations"+
             " under one banner, aligning them with other elves to resist the tyranny of the"+
             " %^BOLD%^%^YELLOW%^sun elves %^BOLD%^%^WHITE%^who, their way misguided, sought to force"+
             " their leadership on all of elvendom. Legend says that there are two other parts"+
             " to the crown, one commissioned by the elven mage %^BOLD%^%^GREEN%^Calideidrathal"+
             " %^BOLD%^%^WHITE%^and the other rescued from the clutches of a %^BOLD%^%^BLACK%^Dragon"+
             "%^BOLD%^%^WHITE%^. The magics inherent in the diadem allowed him to view distant"+
             " enemies to help his people in battle, the information gleaned turning many losses"+
             " into victories.");
    set_ac(-5);
    set_property("enchantment",5);
    set_weight(1);
    set_wear((:TO,"wearme":));
    set_heart_beat(1);
    set_value(15000);
    set_limbs( ({"head"}) );
    set("read","%^BOLD%^%^YELLOW%^Gaze into the %^BOLD%^%^RED%^mirror %^BOLD%^%^YELLOW%^and find that which you seek;\n\nFeel"+
               " secure that the power of your ancestory will %^BOLD%^%^GREEN%^protect %^BOLD%^%^YELLOW%^you from prying eyes.");
}

int wearme(string str){
    object *stuff;
    int i,j, flag;
   if((string)ETO->query_race() !="elf") {
       tell_object(ETO,"The energies within this device does not attune to you.");
       return 0;}
    else;{
   if((int)ETO->query_level() < 35) {
     tell_object(ETO,"The circlet seems too powerful for you to control.");
     return 0;
   }
    stuff = TP->all_armour();
    j = sizeof(stuff);
    for(i=0;i<j;i++) {
        if(!objectp(stuff[i])) continue;
        if((string)stuff[i]->query_type() == "circlet") {
            if(member_array("elven circlet",stuff[i]->query_id()) != -1) {
                flag = 1;
                break;
            }
        }
    }
    if(flag) {
        write("The magic of the ring already worn prevents you from wearing this one!");
        return 0;
    }
   tell_object(ETO,"%^BOLD%^%^RED%^Unintelligable images from ages ago flash in your mind for a moment as you place the circlet on your head.%^RESET%^");
   return 1;
}}

void init(){
    ::init();
    add_action("mirror","mirror");
    add_action("protect","protect");
    }

void failure(){
    tell_object(ETO,"The circlet does not respond, perhaps it may need more time to regain its magical charge.",EETO);
    return 1;
    }

int mirror(){
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    if(query_worn()){
    if(!uses){
    tell_room(ETO,"%^BOLD%^%^RED%^The circlet briefly glows red.");
    return 1;}
    else;{
            tell_room(ETO,"%^BOLD%^WHITE%^The circlet verberates quietly, sparkling slightly.");
                     new("/cmds/spells/m/_magic_mirror")->use_spell(TP,"mirror",14,1,"mage");
            uses--;
            return 1;
            }
    }
    write("You must wear the circlet first.");
    return 1;
}

int protect(){
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
    if(query_worn()){
    if(!uses){
    tell_room(ETO,"%^BOLD%^%^RED%^The circlet briefly glows red.");
    return 1;
    }
    else;{
            tell_room(ETO,"%^BOLD%^GREEN%^Green tendrils burst from the circlet, covering the nearby area with faint magics for a brief moment.");
                     new("/cmds/spells/p/_protection_from_scrying")->use_spell(ETO,ETO,50,100,"mage");
            uses--;
            return 1;
        }
    }
    write("You must wear the ring first.");
    return 1;
}


void heart_beat(){
   if(!objectp(ETO)){
   return ;
   }
   if(uses>0){
   used_time = time();
   }
   if(WAIT_TIME < (time() - used_time)) {
   uses=5;
   }
   if(WAIT_TIME2 > (time() - used_time2)) {
   return;
   }
   if(!TO->query_worn()){
   return ;
   }
   if(ETO->query_hp()<((int)ETO->query_max_hp())/3&&!ETO->query_unconscious()&&!ETO->query_bound()&&uses>0){
      tell_object(ETO,"%^BOLD%^%^WHITE%^The ring feels your pain and heals you completely!%^RESET%^");
   ETO->add_hp(ETO->query_max_hp());
      used_time2 = time();
      uses --;
      return 1;
   }
}

void set_used_time(int x) {
   used_time = x;
}

void set_used_time2(int y) {
   used_time2 = y;
}
