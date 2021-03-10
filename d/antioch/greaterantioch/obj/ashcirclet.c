#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/jewelry/circlet.c";

#define WAIT_TIME 5
#define WAIT_TIME2 100

int used_time;
int used_time2;
int CHARGES;
int CHARGES2;

void create(){
    ::create();
    CHARGES = roll_dice(1,6);
    CHARGES2 = roll_dice(1,6);
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
    set_type("helm");
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
    set_ac(-3);
    set_property("enchantment",3);
    set_weight(1);
    //uses = 3;
    set_value(15000);
    set_limbs( ({"head"}) );
    set("read","%^BOLD%^%^YELLOW%^Gaze into the %^BOLD%^%^RED%^mirror %^BOLD%^%^YELLOW%^and find that which you seek;\n\nFeel"+
               " secure that the power of your ancestory will %^BOLD%^%^GREEN%^protect %^BOLD%^%^YELLOW%^you from prying eyes.");
}
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
   // if(WAIT_TIME > (time() - used_time)) {
   //     failure();
   if(!CHARGES){
        return 1;}
    else;{
            //used_time = time();
            tell_room(ETO,"%^BOLD%^WHITE%^The circlet verberates quietly, sparkling slightly.");
                     new("/cmds/spells/m/_magic_mirror")->use_spell(TP,"mirror",14,1,"mage");
        //    uses--;
            CHARGES--;
            return 1;
            }
    }
    write("You must wear the ring first.");
    return 1;
}

//int reset_circlet(){
//    if(uses < 1){
//        tell_room(ETO,"%^BOLD%^%^RED%^The circlet briefly glows red.");
//        used_time = time();
//        }}

int protect(){
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    if(query_worn()){
    if(WAIT_TIME2 > (time() - used_time2)) {
    failure();
    if(!CHARGES2){
    //CHARGES2 = roll_dice(1,6);
    tell_room(ETO,"%^BOLD%^%^RED%^The circlet briefly glows red.");
    used_time2 = time();
    return 1;
    }
    else;{
            tell_room(ETO,"%^BOLD%^GREEN%^Green tendrils burst from the circlet, covering the nearby area with faint magics for a brief moment.");
                     new("/cmds/spells/p/_protection_from_scrying")->use_spell(ETO,ETO,50,100,"mage");
            CHARGES2--;
            return 1;
        }
    }
    write("You must wear the ring first.");
    return 1;
}}

//void reset_circlet2(){
   // if(!CHARGES2){
    //CHARGES2 = roll_dice(1,6);
   // tell_room(ETO,"%^BOLD%^%^RED%^The circlet briefly glows red.");
   // used_time2 = time();}
   // }


void set_used_time(int x) {
    used_time = x;
    }

//int query_uses() { return uses; }
