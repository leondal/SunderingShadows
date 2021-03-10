#include <std.h>
inherit OBJECT;
string LUCIFER, end, array;
int death,x,stre,dex,maxhp,dum,dum1,inte,plat,gold,sil,cop,ele,numb;
void create() {
  ::create();
    death = 0;
set_id(({
    "box","cards","A small box","small box"
         })); 
set_short("%^RED%^A Small Box%^RESET%^");
set_long(
@LUCIFER
This is an old wooden box with an intricate woodcut on its face.
Inside the box you see a deck of cards.  Each card is made of 
a thin sheet of ivory and has complicated patterns engraved 
into it.  You are free to select up to four cards from this 
%^RED%^Deck of Many Things%^RESET%^, but beware, as the rewards are great, the 
dangers are equal in magnitude.  You can see something
engraved into the box.  It would be wise to %^CYAN%^read%^RESET%^ it.
LUCIFER
);
set_weight(1);
set("value",500);
}

void init(){
     ::init();
     add_action("draw_cards","draw");
     add_action("read_cards","read");
   }

   int read_cards(string str){
     string tmp;
     if(!str)return notify_fail("What do you want to read?\n");
     sscanf(str,"%s",tmp);
     if (tmp == "box")
       {
	 write(
@LUCIFER
This is %^RED%^A Deck of Many Things%^RESET%^.  To use it, type draw <#> cards from deck.
You may pick up to 4 cards and no more.  All effects of this item are 
permanent and the Deck will destroy itself after use.
LUCIFER
);
       }
     return 1;
   }
     
     int draw_cards(string str){
     int num, count, card;
     if(!str)return notify_fail("How many cards do you want to draw?\n");
     sscanf(str, "%d cards from deck", num);
     if (num >= 5)
       {
 	 write("You may ONLY draw up to 4 cards!!");
	 num = 4;
       }
     
     count = 0;
     write ("You selected " +num+ " cards.\n");      
       do
	 {
     card = (random(11)+11);
     count=count + 1;
     switch(12){

       case 1:
       write ("You drew the Sun.\n");
       TP->add_exp(50,000);
       write ("You have been granted more experience.\n");
       write ("You better hope your next draws are as lucky.\n");
       break;
       
       case 2:
       write ("You draw the Talon.\n");
       write ("Some object has been stolen from your person.\n");
       array = deep_inventory(TP);
       numb = random(sizeof(array));
       array[numb]->remove();
       break;
       
       case 3:
       write ("You draw the Jester.\n");
       write ("You gain 10,000 exp and must draw again.\n");
       count--;
       TP->add_exp(10,000);
       break;
       
     case 4:
       write ("You draw the Fool.\n");
       write ("You lose 10,000 exp and must draw again.\n");
       count--;
       TP->add_exp(-10000);
       break;

     case 5:
       write ("You draw the Throne.\n");
       write ("Your charisma has been increased.\n");
       if (TP->query_stats("charisma") <= 17){
           TP->set_stats("charisma",18);
     }
       else{
       new("/d/islands/carcosa/misc/gems.c")->move(TP);
       write ("A bag of gems worthy of a king appears in your inventory!\n");
     }
       break;

     case 6:
       write ("You drew the Idiot.\n");
       write (
@LUCIFER
As the card is pulled, a beam of light shoots forth 
from its runes and blinds you as it covers your face.  
As your vision returns, you feel mentally drained.
LUCIFER
); 
       dum = roll_dice(1,4);
       inte = TP->query_stats("intelligence");
       inte = inte - dum;
       TP->set_stats("intelligence",inte);
       write ("You lose " +dum+ " points of intelligence.\n");
       break;
       
     case 7:
       write ("You draw the Key.\n");
       write ("You are granted a magic weapon.\n");
       break;
       
     case 8:
       write ("You draw the Void.\n");
       write (
@LUCIFER
As you pull the card from the deck, hole opens up
beneath your feet.  You begin to fall through a
void of nothingness and suddenly come in contact 
with the ground.  Splinters of the bones that once
made up your legs shoot through your body killing
you instantly.
LUCIFER
	      );
       TP->do_damage("torso",1000);
       break;
       
     case 9:
       write ("You draw the Gem.\n");
       new("/d/islands/carcosa/misc/gem.c")->move(TP);
       write ("A large red ruby appears in your inventory!\n");
       break;
       
     case 10:
       write ("You draw the Flame.\n");
       write (
@LUCIFER
When you touch the card %^RED%^FIRE%^RESET%^ jumps from its
surface and runs covers your body.  The blast of
power charrs your skin and leaves a smell of burnt
hair and flesh in the room.
LUCIFER
	      );
       TP->do_damage("torso",(roll_dice(8,6)));
       break;
       
     case 11:
       write ("You draw the Moon.\n");
       write ("You feel strengthened as the power of this card affects you.\n");
       stre = TP->query_stats("strength");
       stre = stre + (roll_dice(1,2));
       TP->set_stats("strength",stre);
       break;
       
     case 12:
       write ("You draw the Skull");
       write (
@LUCIFER
By pulling this card, you have summoned the attention
of death.  He has sent a lesser spawn to destroy you
and if he succeeds, this death will be a most 
unpleasant one!
LUCIFER
     );
       death = 1;
       break;
       
     case 13:
       write ("You draw the Star.\n");
       write ("You feel more nimble as the power of this card washes over you.\n");
       TP->set_stats("dexterity",(TP->query_stats("dexterity")+random(1)+1));
       break;

     case 14:
       write ("You draw ruin.\n");
       write (
@LUCIFER
As this card is drawn, you feel a slight tug on your
purse.  Looking down to investigate you see that your 
money is now gone and can only assume that some diety 
is that much richer.
LUCIFER
);
       plat = TP->query_money("platnum");
       TP->add_money("platnum",(-(plat)));

       gold = TP->query_money("gold");
       TP->add_money("gold",(-(gold)));

       sil = TP->query_money("silver");
       TP->add_money("silver",(-(sil)));

       ele = TP->query_money("electrum");
       TP->add_money("electrum",(-(ele)));

       cop = TP->query_money("copper");
       TP->add_money("copper",(-(cop)));
       break;

     case 15:
       write ("You draw Comet.\n");
       if(TP->is_class("fighter") || TP->is_class("ranger") || TP->is_class("paladin")){
	 stre = TP->query_stats("strength") + 3;
	 TP->set_stats("strength",stre);}
       
       if(TP->is_class("thief") || TP->is_class("bard")){
	 TP->set_stats("dexterity",(TP->query_stats("dexterity")+3));}
       if(TP->is_class("mage")){
           TP->set_stats("intelligence",(TP->query_stats("intelligence")+3));}
       if(TP->is_class("cleric") || TP->is_class("druid")){
           TP->set_stats("wisdom",(TP->query_stats("wisdom")+3));}
       write ("Your major stat has been increased!\n");
       break;

     case 16:
       write ("You draw Euryale.\n");
       dex = TP->query_stats("intelligence");
       dex = dex - 2;
       TP->set_stats("dexterity",dex);
       write ("You lose 2 points of dexterity.\n");
       break;

     case 17:
       write ("You draw the Knight.\n");
       dum = roll_dice(1,8);
       maxhp = TP->query_max_hp();
       maxhp = maxhp + dum;
       TP->set_max_hp(maxhp);
       write ("You gain " +dum+ " hit points as this card affects you.\n");
       break;

     case 18:
       write ("You draw the Donjon.\n");
       stre = TP->query_stats("strength");
       stre = stre - 2;
       TP->set_stats("strength",stre);
       write ("You lose 2 points of strength.\n");
       break;       

     case 19:
       write ("You draw the Vizier.\n");
       
       break;

     case 20:
       write ("You draw Balance.  Prepare to be judged!\n");
       break;

     case 21:
       write ("You draw Fates.\n");
       write (
@LUCIFER
Red and purple lightening shoot forth from the card you just
drew and cover your body with energy.  When the smoke clears,
You can see runes carved deep into the flesh of your arms.
There is some text on the runes you believe you can make
out.
LUCIFER
	      );
       
       break;

     case 22:
       write ("You draw the Rogue.\n");
       dum = roll_dice(1,8);
       maxhp = TP->query_max_hp();
       maxhp = maxhp - dum;
       TP->set_max_hp(maxhp);
       write ("You lose " +dum+ " hit points as this card affects you.\n");
       break;
       
     }
   }while (count < num);


     if(death==1)
       {
	 if(!present("death",ETO)) new("/d/islands/carcosa/mon/death.c")->move(environment(TP));
       }
     
     write ("The Deck of Many Things crumbles in your hands.\n");
     TO->remove();
     return 1;
   }
     




