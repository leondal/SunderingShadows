#include <std.h>
inherit ARMOUR;

#define WAIT_TIME 14400
int used_time;

void create(){
   ::create();
   set_name("%^BOLD%^%^WHITE%^Platinum ring of stars%^RESET%^");
   set_id(({"ring","ring of stars","platinum ring","star ring","platinum ring of stars"}));
   set_short("%^BOLD%^%^WHITE%^A sparkling platinum ring%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This sparkling ring is made out of the purest"
" platinum.  Inset upon the top of the ring is a very large princess cut diamond"
" that shines in the light and reflects prismatic sprays of color throughout the"
" room.  A small inscription is written on the inside of the band.%^RESET%^\n");
   set_lore("%^BOLD%^%^WHITE%^These rings are rare and rumored to be made by a"
" wayward priest who dappled in the arts of magic.  Becuase of the mad wizards"
" inexperience, the rings were thought to be to dangerous and unreliable for"
" general use.  All the known copies were gathered together and burried deep"
" within the Barrier Mountains.%^RESET%^");
   set_language("common");
   set_read("%^YELLOW%^This is the fabled prismatic ring of stars.\nUse it wisely"
" as it casts prismatic spray at your enemies."
"\nYou may 'aim ring at <target>' to see the wonders this ring creates!%^RESET%^");
   set_weight(2);
   set_value(2000);
   set_type("ring");
   set_limbs(({"right hand"}));
   set_size(2);
   set_property("enchantment",0);
   set_ac(0);
   set_wear((:this_object(),"wearme":));
   set_heart_beat(1);
}
int wearme(string str){
      tell_room(environment(ETO),"%^BOLD%^%^WHITE%^%^As "+ETOQCN+" slips on the ring, bright %^RED%^c%^BLUE%^o%^YELLOW%^l%^CYAN%^o%^RED%^r%^YELLOW%^s %^WHITE%^fill the room.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^Bright %^RED%^c%^BLUE%^o%^YELLOW%^l%^CYAN%^o%^RED%^r%^YELLOW%^s %^WHITE%^fill the room as you slip on the ring.%^RESET%^");
   return 1;
}
void init(){
   ::init();
   if(!objectp(TP)) return;
   if (!objectp(ETO)) return;
   if (TP != ETO) return;
   add_action("aim","aim");
}
void aim(string str){
   string tmp;
   object obj;
   if(!str) return notify_fail("Aim what at what?\n");
   if(sscanf(str,"ring at %s",tmp)){
   if (TP->query_bound()||TP->query_unconscious()||TP->query_paralyzed()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }}
    if(!TO->query_worn()) return notify_fail("You need to be wearing the ring.\n");

    if(WAIT_TIME > (time() - used_time)) {
      return 1;}

    if(!(obj = present(str, ETP))) return notify_fail("No suitable"+str" here!\n");{
        switch(random(5)){
          case 0..4:
          tell_object(ETO,"You caress the ring softly and then point it at "+obj->QCN+" but the ring tricks you and forces you to turn your hand against yourself!");
          tell_object(obj,""+TPQCN+" caresses the ring softly then points it directly at you but something goes wrong and "+TP->query_subjective()+" turns the ring against "+TP->query_objective()+"self!");
          tell_room(ETP,""+TPQCN+" caresses the ring and then points it at "+obj->query_cap_name()+" but something goes terribly wrong and "+TP->query_subjective()+" turns the ring against "+TP->query_objective()+"self!",({TP,obj}));
          new("/cmds/spells/m/_magic_mirror")->use_spell(TP,"mirror",14,1,"mage");
          uses --;
          break;}
    return 1;}
    }

void set_used_time(int x) {
   used_time = x;
}
