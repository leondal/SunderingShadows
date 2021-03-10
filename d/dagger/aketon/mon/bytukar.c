#include "/d/dagger/aketon/short.h"
#include <move.h>
#include <daemons.h>

#define SAVE_PATH "/d/save/aketon/"

inherit MONSTER;

mapping making1,making2,making3,making4,making5;

void create() {
   ::create();
   set_name("bytukar");
   set_id( ({"bytukar","tailor"}) );
   set_short("Bytukar the tailor");
   set("aggressive", 0);
   set_long("He is an old man who makes clothes for a living here in the "
      "great elven city of Aketon.");
   set_gender("male");
   set_alignment(1);
   set("race","elf");
   add_money( "gold",random(30) );
   set_body_type("human");
   set_hd(30,8);
   set_hp(200);
   set_max_hp(query_hp());
   if( file_exists(SAVE_PATH+query_name()+".tailor.o") )
      restore_object(SAVE_PATH+query_name()+".tailor");
   if(!making1)
      making1 = ([]);
   if(!making2)
      making2 = ([]);
   if(!making3)
      making3 = ([]);
   if(!making4)
      making4 = ([]);
   if(!making5)
      making5 = ([]);
}

void init() {
   ::init();
   add_action("buy_func","buy");
   add_action("pickup_func","pickup");
}

int buy_func(string str) {
   object obj;
   int num,previlege_check;
   if(!str)
      return notify_fail("Buy what?\n");
   sscanf(str,"%d",num);
   if( member_array( num,({1,2,3,4,5}) ) == -1 )
      return notify_fail("I don't make those!\n");
   if( (int)SAVE_D->is_member("aketon_list",TPQN) != -1)
      previlege_check = 1;
   else if( (string)TP->query_race() == "human" )
      previlege_check = 2;
   else
      previlege_check = 3;
   switch(num) {
      case 1:
         if( (string)TP->query_gender() != "male" )
            return notify_fail("It is for males only!\n");
         if( making1[TPQN] )
            return notify_fail("The tailor is making you one already!\n");
         switch(previlege_check) {
            case 1:
               if( !TP->query_funds("gold",250) )
                  return notify_fail("You don't have enough money!\n");
               break;
            case 2:
               if( !TP->query_funds("gold",1000) )
                  return notify_fail("You don't have enough money!\n");
               break;
            case 3:
               if( !TP->query_funds("gold",500) )
                  return notify_fail("You don't have enough money!\n");
               break;
         }
         tell_object(TP,"Bytukar takes your money.");
         command("say Come back in 20 minutes to pickup the item.");
         switch(previlege_check) {
            case 1:
               TP->use_funds("gold",250);
               break;
            case 2:
               TP->use_funds("gold",1000);
               break;
            case 3:
               TP->use_funds("gold",500);
               break;
         }
         break;
      case 2..3:
         if(num == 2) {
            if( (string)TP->query_gender() != "male" )
               return notify_fail("It is for males only!\n");
            if( making2[TPQN] )
               return notify_fail("The tailor is making you one "
                  "already!\n");
         }
         if(num == 3) {
            if( (string)TP->query_gender() != "female" )
               return notify_fail("It is for females only!\n");
            if( making3[TPQN] )
               return notify_fail("The tailor is making you one "
                  "already!\n");
         }
         switch(previlege_check) {
            case 1:
               if( !TP->query_funds("gold",200) )
                  return notify_fail("You don't have enough money!\n");
               break;
            case 2:
               if( !TP->query_funds("gold",800) )
                  return notify_fail("You don't have enough money!\n");
               break;
            case 3:
               if( !TP->query_funds("gold",400) )
                  return notify_fail("You don't have enough money!\n");
               break;
         }
         tell_object(TP,"Bytukar takes your money.");
         command("say Come back in 20 minutes to pickup the item.");
         switch(previlege_check) {
            case 1:
               TP->use_funds("gold",200);
               break;
            case 2:
               TP->use_funds("gold",800);
               break;
            case 3:
               TP->use_funds("gold",400);
               break;
         }
         break;
      case 4..5:
         if(num == 4) {
            if( (string)TP->query_gender() != "male" )
               return notify_fail("It is for males only!\n");
            if( making4[TPQN] )
               return notify_fail("The tailor is making you one "
                  "already!\n");
         }
         if(num == 5) {
            if( (string)TP->query_gender() != "female" )
               return notify_fail("It is for females only!\n");
            if( making5[TPQN] )
               return notify_fail("The tailor is making you one "
                  "already!\n");
         }
         switch(previlege_check) {
            case 1:
               if( !TP->query_funds("gold",100) )
                  return notify_fail("You don't have enough money!\n");
               break;
            case 2:
               if( !TP->query_funds("gold",400) )
                  return notify_fail("You don't have enough money!\n");
               break;
            case 3:
               if( !TP->query_funds("gold",200) )
                  return notify_fail("You don't have enough money!\n");
               break;
         }
         tell_object(TP,"Bytukar takes your money.");
         command("say Come back in 20 minutes to pickup the item.");
         switch(previlege_check) {
            case 1:
               TP->use_funds("gold",100);
               break;
            case 2:
               TP->use_funds("gold",400);
               break;
            case 3:
               TP->use_funds("gold",200);
               break;
         }
         break;
   }
   switch(num) {
      case 1:
         making1 += ([ TPQN : ({ time() , num }) ]);
         break;
      case 2:
         making2 += ([ TPQN : ({ time() , num }) ]);
         break;
      case 3:
         making3 += ([ TPQN : ({ time() , num }) ]);
         break;
      case 4:
         making4 += ([ TPQN : ({ time() , num }) ]);
         break;
      case 5:
         making5 += ([ TPQN : ({ time() , num }) ]);
         break;
   }
   save_object(SAVE_PATH+query_name()+".tailor");
   return 1;
}

int pickup_func(string str) {
   object obj;
   int num;
   string name;
   if(!str)
      return notify_fail("Pickup what?\n");
   sscanf(str,"%d",num);
   if(member_array( num,({1,2,3,4,5}) ) == -1)
      return notify_fail("Pickup <item_number>\n");
   if( !making1[TPQN] && !making2[TPQN] && !making3[TPQN] && !making4[TPQN]
      && !making5[TPQN] )
      return notify_fail("You didn't buy anything here!\n");
   if(num == 1) {
      if(!making1[TPQN])
         return notify_fail("You didn't buy any tuxedo here!\n");
      else {
         if(time() - making1[TPQN][0] < 1200) {
            if(time() - making1[TPQN][0] < 200) {
               command("say I just started the drawing the true size "
                  "paper sample, it takes me about twenty minutes to "
                  "finish making it.");
               return 1;
            }
            if(time() - making1[TPQN][0] < 600) {
               command("say I'm still cutting the clothe, come back "
                  "later.");
               return 1;
            }
            if(time() - making1[TPQN][0] < 1100) {
               command("say Making a suit takes time you know ... ");
               return 1;
            }
            command("say Almost done ... give me some more time ... ");
            return 1;
         }
         obj = new(OPATH+"tuxedo");
         obj->set_own(TPQN);
         obj->set_size( TP->query_size() );
         name = "tuxedo";
         map_delete(making1,TPQN);
         save_object(SAVE_PATH+query_name()+".tailor");
      }
   }
   if(num == 2) {
      if( !making2[TPQN] )
         return notify_fail("You didn't buy any gentleman's jacket "
            "here!\n");
      else {
         if(time() - making2[TPQN][0] < 1200) {
            if(time() - making2[TPQN][0] < 200) {
               command("say I just started the drawing the true size "
                  "paper sample, it takes me about twenty minutes to "
                  "finish making it.");
               return 1;
            }
            if(time() - making2[TPQN][0] < 600) {
               command("say I'm still cutting the clothe, come back "
                  "later.");
               return 1;
            }
            if(time() - making2[TPQN][0] < 1100) {
               command("say Making a jacket takes time you know ... ");
               return 1;
            }
            command("say Almost done ... give me some more time ... ");
            return 1;
         }
         obj = new(OPATH+"g_jacket");
         obj->set_own(TPQN);
         obj->set_size( TP->query_size() );
         name = "jacket";
         map_delete(making2,TPQN);
         save_object(SAVE_PATH+query_name()+".tailor");
      }
   }
   if(num == 3) {
      if( !making3[TPQN] )
         return notify_fail("You didn't buy any lady's jacket here!\n");
      else {
         if(time() - making3[TPQN][0] < 1200) {
            if(time() - making3[TPQN][0] < 200) {
               command("say I just started the drawing the true size "
                  "paper sample, it takes me about twenty minutes to "
                  "finish making it.");
               return 1;
            }
            if(time() - making3[TPQN][0] < 600) {
               command("say I'm still cutting the clothe, come back "
                  "later.");
               return 1;
            }
            if(time() - making3[TPQN][0] < 1100) {
               command("say Making a jacket takes time you know ... ");
               return 1;
            }
            command("say Almost done ... give me some more time ... ");
            return 1;
         }
         obj = new(OPATH+"l_jacket");
         obj->set_own(TPQN);
         obj->set_size( TP->query_size() );
         name = "jacket";
         map_delete(making3,TPQN);
         save_object(SAVE_PATH+query_name()+".tailor");
      }
   }
   if(num == 4) {
      if( !making4[TPQN] )
         return notify_fail("You didn't buy any trousers here!\n");
      else {
         if(time() - making4[TPQN][0] < 1200) {
            if(time() - making4[TPQN][0] < 200) {
               command("say I just started the drawing the true size "
                  "paper sample, it takes me about twenty minutes to "
                  "finish making it.");
               return 1;
            }
            if(time() - making4[TPQN][0] < 600) {
               command("say I'm still cutting the clothe, come back "
                  "later.");
               return 1;
            }
            if(time() - making4[TPQN][0] < 1100) {
               command("say Making trousers take time you know ... ");
               return 1;
            }
            command("say Almost done ... give me some more time ... ");
            return 1;
         }
         obj = new(OPATH+"trousers");
         obj->set_own(TPQN);
         obj->set_size( TP->query_size() );
         name = "trousers";
         map_delete(making4,TPQN);
         save_object(SAVE_PATH+query_name()+".tailor");
      }
   }
   if(num == 5) {
      if( !making5[TPQN] )
         return notify_fail("You didn't buy any skirt here!\n");
      else {
         if(time() - making5[TPQN][0] < 1200) {
            if(time() - making5[TPQN][0] < 200) {
               command("say I just started the drawing the true size "
                  "paper sample, it takes me about twenty minutes to "
                  "finish making it.");
               return 1;
            }
            if(time() - making5[TPQN][0] < 600) {
               command("say I'm still cutting the clothe, come back "
                  "later.");
               return 1;
            }
            if(time() - making5[TPQN][0] < 1100) {
               command("say Making a skirt takes time you know ... ");
               return 1;
            }
            command("say Almost done ... give me some more time ... ");
            return 1;
         }
         obj = new(OPATH+"skirt");
         obj->set_own(TPQN);
         obj->set_size( TP->query_size() );
         name = "skirt";
         map_delete(making5,TPQN);
         save_object(SAVE_PATH+query_name()+".tailor");
      }
   }
   if( (int)obj->move(TP) != MOVE_OK ) {
      command("say You cannot carry it, I will drop it on the floor.");
      obj->move(ETP);
      return 1;
   }
   command("say Here is your new "+name+". Please take great care of it.");
   command("smile "+TPQN);
   obj->move(TP);
   return 1;
}
