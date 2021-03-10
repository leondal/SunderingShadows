//skill.c
// fix in init_vars for the skill bonuses Saide added being included in query_thief_skills()
// changed instances of display_skills, to display_skills_new per Styx's change in _skills.c -Ares 8/21/05

#include <std.h>

inherit OBJECT;

int count_points;
int add;
int PP,OL,FRT,MS,HIS,DN,CW,RL;
string hold;

void calc_thief_skills();
void init_vars();

void create() {
   ::create();
   set_name("skill chest");
   set_short("");
   set_long("offer this please");
   set_id(({"skill chest","skills","chest"}));
}

void init() {
   int level;
   ::init();
   if(TP->is_class("thief"))
      level = TP->query_class_level("thief");
   if(TP->is_class("bard"))
      level = TP->query_class_level("bard");
   if(level == 1)
      calc_thief_skills();
   else {
      init_vars();
      "/cmds/mortal/_skills"->display_skills_new(TP);
      if(!TP->is_class("bard"))
         write("You have a maximum of 30 points to add, no more than 15 on a skill.");
      else
         write("You have a maximum of 15 points to add.");
      write("To abort or start over enter '**' at any prompt");
      write("Input addition to Pick pockets");
      input_to("PP2");
   }
}

int drop() {return 1;}
int save_me(string file) {return 1;}
int get() {return 0;}

void init_vars() {
   count_points=0;
   PP = TP->query_base_thief_skill("pick pockets");
   OL = TP->query_base_thief_skill("open lock");
   FRT = TP->query_base_thief_skill("find/remove traps");
   MS = TP->query_base_thief_skill("move silently");
   HIS = TP->query_base_thief_skill("hide in shadows");
   DN = TP->query_base_thief_skill("detect noise");
   CW = TP->query_base_thief_skill("climb walls");
   RL = TP->query_base_thief_skill("read languages");
}

void ABORT_RESTART1(string str) {
  if (str == "**") {
    write("Aborted skill advancement above initial skills.");
    TO->remove();
    return;
  }
  init_vars();
  calc_thief_skills();
}

void ABORT_RESTART2(string str) {
  if (str == "**") {
    write("Aborted skill advancement.");
    TO->remove();
    return;
  }
  init_vars();
  "/cmds/mortal/_skills"->display_skills_new(TP);
  if(!TP->is_class("bard"))
    write("You have a maximum of 30 points to add, no more than 15 on a skill.");
  else
    write("You have a maximum of 15 points to add.");
  write("To abort or start over enter '**' at any prompt");
  write("Input addition to Pick pockets");
  input_to("PP2");
}

void calc_thief_skills() {
   int dex;
   string race;
   int change;
   int level;
   //string theclass;

   count_points = 0;
   // initial settings for new thieves //
   PP=15;
   OL=10;
   FRT=5;
   MS=10;
   HIS=5;
   DN=15;
   CW=60;
   RL=0;
   // add or subtract percentage points based on race, dexterity //
   race=TP->query_race();
   dex=TP->query_base_stats("dexterity");
   switch(race) {
   case "beastman":
      OL-=5;
      FRT-=5;
      MS+=5;
      HIS+=5;
      CW+=5;
      RL-=5;
      break;
   case "dwarf":
      OL+=10;
      FRT+=15;
      CW-=10;
      RL-=5;
      break;
   case "drow":
   case "elf":
      PP+=5;
      OL-=5;
      MS+=5;
      HIS+=10;
      DN+=5;
      break;
   case "gnoll":
      PP-=5;
      OL-=5;
      HIS+=5;
      DN+=5;
      RL-=10;
      break;
   case "gnome":
      OL+=5;
      FRT+=10;
      MS+=5;
      HIS+=5;
      DN+=10;
      CW-=15;
      break;
   case "goblin":
      PP+=5;
      FRT+=10;
      MS+=5;
      HIS+=5;
      CW-=10;
      RL-=10;
      break;
   case "half-drow":
      PP+=5;
      FRT+=5;
      MS+=5;
      HIS+=10;
      DN+=5;
      break;
   case "half-elf":
      PP+=10;
      HIS+=5;
      break;
   case "half-orc":
      PP-=5;
      OL+=5;
      FRT+=5;
      DN+=5;
      CW+=5;
      RL-=10;
      break;
   case "halfling":
      PP+=5;
      OL+=5;
      FRT+=5;
      MS+=10;
      HIS+=15;
      DN+=5;
      CW-=15;
      RL-=5;
      break;
   case "hobgoblin":
      OL+=5;
      FRT+=5;
      RL-=10;
      break;
   case "kobold":
      PP+=5;
      MS+=5;
      HIS+=10;
      DN+=10;
      CW-=15;
      RL-=10;
      break;
   case "ogre mage":
      PP-=5;
      CW-=15;
      RL+=5;
      break;
   case "orc":
      PP-=5;
      HIS+=5;
      DN+=5;
      CW+=5;
      RL-=10;
      break;
   case "voadkyn":
      PP-=5;
      OL-=5;
      HIS+=5;
      DN+=5;
      break;
   default: 
      break;
   }
   switch(dex) {
   case 9:
      PP-=15;
      OL-=10;
      FRT-=10;
      MS-=20;
      HIS-=10;
      break;
   case 10:
      PP-=10;
      OL-=5;
      FRT-=10;
      MS-=15;
      HIS-=5;
      break;
   case 11:
      PP-=5;
      FRT-=5;
      MS-=10;
      break;
   case 12:
      MS-=5;
      break;
   case 16:
      OL+=5;
      break;
   case 17:
      PP+=5;
      OL+=10;
      MS+=5;
      HIS+=5;
      break;
   case 18:
      PP+=10;
      OL+=15;
      FRT+=5;
      MS+=10;
      HIS+=10;
      break;
   case 19:
      PP+=15;
      OL+=20;
      FRT+=10;
      MS+=15;
      HIS+=15;
      break;
   case 20:
      PP+=20;
      OL+=25;
      FRT+=15;
      MS+=20;
      HIS+=20;
      break;
   default: break;
   }
   // save base values to TP stats //
   if(TP->is_class("thief")){
      TP->set_thief_skill("open lock",OL);
      TP->set_thief_skill("find/remove traps",FRT);
      TP->set_thief_skill("move silently",MS);
      TP->set_thief_skill("hide in shadows",HIS);
   }
   TP->set_thief_skill("pick pockets",PP);
   TP->set_thief_skill("detect noise",DN);
   TP->set_thief_skill("climb walls",CW);
   TP->set_thief_skill("read languages",RL);
   // read in player's distribution of 60 points //
   if(TP->is_class("thief")) {
      write("You have 60 percentage points to distribute among your thieving skills.");
      write("You may add no more than 30 points to a single attribute.\n");
   }
   else {
      write("You have 30 percentage points to distribute among your thieving skills.");
      write("You may add no more than 15 points to a single attribute.\n");
   }
   //   write("You will not be allowed to edit once started.");
   //   write("So consider carefully.");
   write("Your current stats are:");
   "/cmds/mortal/_skills"->display_skills_new(TP);
   write("You can abort or start over by typing '**'");
   if(TP->is_class("thief") || TP->is_class("bard")) {
      write("Please enter addition to Pick pockets:");
      input_to("PP1");
   }
}

void PP1(string str) {
   int temp;
   int temp2, x;

   add = 0;
   if(PP>95) PP = 95;
   if(!str)
      input_to("PP1");
   else  if (str == "**" ) {
     write("Please enter '**' again to abort, or anything else to restart your skills");
     input_to("ABORT_RESTART1");
   } else {
      if(sscanf(str,"%d",add) != 1) {
         write("Please enter a number:");
         input_to("PP1");
      }
      else {
         if(add < 0) {
            write("Please input again -- 0 or more:");
            input_to("PP1");
         }
         else {
            if(add > 15 && TP->is_class("bard")) {
               write("Please input again -- 15 or less:");
               input_to("PP1");
            }
            else {
               if(add > 30) {
                  write("Please input again -- under 30:");
                  input_to("PP1");
               }
               else {
                  if((PP+add)>95) {
                     write("Please input again -- skills may not exceed 95:");
                     input_to("PP1");
                  }
                  else {
                     PP+=add;
                     count_points+=add;
                     if(TP->is_class("bard")) {
                        write("Please enter addition to Detect noise:");
                        input_to("DN1");
                     }
                     else {
                        write("Please enter addition to Open locks:");
                        input_to("OL1");
                     }
                  }  
               }
            }
         }
      }
   }
}

void OL1(string str) {
   int temp;
   int temp2, x;

   add = 0;
   if(OL>95) OL = 95;
   if(!str)
      input_to("OL1");
   else  if (str == "**" ) {
     write("Please enter '**' again to abort, or anything else to restart your skills");
     input_to("ABORT_RESTART1");
   } else {
      if(sscanf(str,"%d",add) != 1) {
         write("Please enter a number:");
         input_to("OL1");
      }
      else {
         if(add < 0) {
            write("Please input again -- 0 or more:");
            input_to("OL1");
         }
         else {
            if(add > 15 && TP->is_class("bard")) {
               write("Please input again -- 15 or less:");
               input_to("OL1");
            }
            else {
               if(add > 30) {
                  write("Please input again -- under 30:");
                  input_to("OL1");
               }
               else {
                  if((OL+add)>95) {
                     write("Please input again -- skills may not exceed 95:");
                     input_to("OL1");
                  }
                  else {
                     OL+=add;
                     count_points+=add;
                     write("Please enter addition to Find/remove traps:");
                     input_to("FRT1");
                  }
               }
            }

         }
      }
   }
}

void FRT1(string str) {
   int temp;
   int temp2, x;

   add = 0;
   if(FRT>95) FRT = 95;
   if(!str)
      input_to("FRT1");
   else  if (str == "**" ) {
     write("Please enter '**' again to abort, or anything else to restart your skills");
     input_to("ABORT_RESTART1");
   } else {
      if(sscanf(str,"%d",add) != 1) {
         write("Please enter a number:");
         input_to("FRT1");
      }
      else {
         if(add < 0) {
            write("Please input again -- 0 or more:");
            input_to("FRT1");
         }
         else {
            if(add > 15 && TP->is_class("bard")) {
               write("Please input again -- 15 or less:");
               input_to("FRT1");
            }
            else {
               if(add > 30) {
                  write("Please input again -- under 30:");
                  input_to("FRT1");
               }
               else {
                  if((FRT+add)>95) {
                     write("Please input again -- skills may not exceed 95:");
                     input_to("FRT1");
                  }
                  else {
                     FRT+=add;
                     count_points+=add;
                     write("Please enter addition to Move silently:");
                     input_to("MS1");
                  }
               }
            }
         }
      }
   }
}

void MS1(string str) {
   int temp;
   int temp2, x;

   add = 0;
   if(MS>95) MS = 95;
   if(!str)
      input_to("MS1");
   else  if (str == "**" ) {
     write("Please enter '**' again to abort, or anything else to restart your skills");
     input_to("ABORT_RESTART1");
   } else {
      if(sscanf(str,"%d",add) != 1) {
         write("Please enter a number:");
         input_to("MS1");
      }
      else {
         if(add < 0) {
            write("Please input again -- 0 or more:");
            input_to("MS1");
         }
         else {
            if(add > 15 && TP->is_class("bard")) {
               write("Please input again -- 15 or less:");
               input_to("MS1");
            }
            else {
               if(add > 30) {
                  write("Please input again -- under 30:");
                  input_to("MS1");
               }
               else {
                  if((MS+add)>95) {
                     write("Please input again -- skills may not exceed 95:");
                     input_to("MS1");
                  }
                  else {
                     MS+=add;
                     count_points+=add;
                     write("Please enter addition to Hide in shadows:");
                     input_to("HIS1");
                  }
               }
            }
         }
      }
   }
}

void HIS1(string str) {
   int temp;
   int temp2, x;

   add = 0;
   if(HIS>95) HIS = 95;
   if(!str)
      input_to("HIS1");
   else  if (str == "**" ) {
     write("Please enter '**' again to abort, or anything else to restart your skills");
     input_to("ABORT_RESTART1");
   } else {
      if(sscanf(str,"%d",add) != 1) {
         write("Please enter a number:");
         input_to("HIS1");
      }
      else {
         if(add < 0) {
            write("Please input again -- 0 or more:");
            input_to("HIS1");
         }
         else {
            if(add > 15 && TP->is_class("bard")) {
               write("Please input again -- 15 or less:");
               input_to("HIS1");
            }
            else {
               if(add > 30) {
                  write("Please input again -- under 30:");
                  input_to("HIS1");
               }
               else {
                  if((HIS+add)>95) {
                     write("Please input again -- skills may not exceed 95:");
                     input_to("HIS1");
                  }
                  else {
                     HIS+=add;
                     count_points+=add;
                     write("Please enter addition to Detect Noise:");
                     input_to("DN1");
                  }
               }
            }
         }
      }
   }
}

void DN1(string str) {
   int temp;
   int temp2, x;

   add = 0;
   if(DN>95) DN = 95;
   if(!str)
      input_to("DN1");
   else  if (str == "**" ) {
     write("Please enter '**' again to abort, or anything else to restart your skills");
     input_to("ABORT_RESTART1");
   } else {
      if(sscanf(str,"%d",add) != 1) {
         write("Please enter a number:");
         input_to("DN1");
      }
      else {
         if(add < 0) {
            write("Please input again -- 0 or more:");
            input_to("DN1");
         }
         else {
            if(add > 15 && TP->is_class("bard")) {
               write("Please input again -- 15 or less:");
               input_to("DN1");
            }
            else {
               if(add > 30) {
                  write("Please input again -- under 30:");
                  input_to("DN1");
               }
               else {
                  if((DN+add)>95) {
                     write("Please input again -- skills may not exceed 95:");
                     input_to("DN1");
                  }
                  else {
                     DN+=add;
                     count_points+=add;
                     write("Please enter addition to Climb walls:");
                     input_to("CW1");
                  }
               }
            }
         }
      }
   }
}

void CW1(string str) {
   int temp;
   int temp2, x;

   add = 0;
   if(CW>95) CW = 95;
   if(!str)
      input_to("CW1");
   else  if (str == "**" ) {
     write("Please enter '**' again to abort, or anything else to restart your skills");
     input_to("ABORT_RESTART1");
   } else {
      if(sscanf(str,"%d",add) != 1) {
         write("Please enter a number:");
         input_to("CW1");
      }
      else {
         if(add < 0) {
            write("Please input again -- 0 or more:");
            input_to("CW1");
         }
         else {
            if(add > 15 && TP->is_class("bard")) {
               write("Please input again -- 15 or less:");
               input_to("CW1");
            }
            else {
               if(add > 30) {
                  write("Please input again -- under 30:");
                  input_to("CW1");
               }
               else {
                  if((CW+add)>95) {
                     write("Please input again -- skills may not exceed 95:");
                     input_to("CW1");
                  }
                  else {
                     CW+=add;
                     count_points+=add;
                     write("Please enter addition to Read languages:");
                     input_to("RL1");
                  }
               }
            }
         }
      }
   }
}

void RL1(string str) {
   int temp;
   int temp2, x;

   add = 0;
   if(RL>95) RL = 95;
   if(!str)
      input_to("RL1");
   else  if (str == "**" ) {
     write("Please enter '**' again to abort, or anything else to restart your skills");
     input_to("ABORT_RESTART1");
   } else {
      if(sscanf(str,"%d",add) != 1) {
         write("Please enter a number:");
         input_to("RL1");
      }
      else {
         if(add < 0) {
            write("Please input again -- 0 or more:");
            input_to("RL1");
         }
         else {
            if(add > 15 && TP->is_class("bard")) {
               write("Please input again -- 15 or less:");
               input_to("RL1");
            }
            else {
               if(add > 30) {
                  write("Please input again -- under 30:");
                  input_to("RL1");
               }
               else {
                  if((RL+add)>95) {
                     write("Please input again -- skills may not exceed 95:");
                     input_to("RL1");
                  }
                  else {
                     RL+=add;
                     count_points+=add;
                     if(count_points > 30 && TP->is_class("bard") || (count_points > 60)) {
                        init_vars();
                        if(TP->is_class("bard"))
                           write("You have exceeded the maximum number of points: 30.");
                        else
                           write("You have exceeded the maximum number of points: 60.");           
                        //write("Please reconsider your additions and reenter them.");
                        //count_points = 0;
			//write("Please enter your additions to Pick pockets");
                        //input_to("PP1");
			write("Please enter '**' to abort, or anything else to restart your skills");
			input_to("ABORT_RESTART1");
                        return;
                     }
                     else {
                        TP->set_thief_skill("pick pockets",PP);
                        TP->set_thief_skill("open lock",OL);
                        TP->set_thief_skill("find/remove traps",FRT);
                        TP->set_thief_skill("move silently",MS);
                        TP->set_thief_skill("hide in shadows",HIS);
                        TP->set_thief_skill("detect noise",DN);
                        TP->set_thief_skill("climb walls",CW);
                        TP->set_thief_skill("read languages",RL);
                        write("Thieves' skills advancement complete.");
                        TP->set_advanced(((int)TP->query_advanced()-1));
                        TO->remove();
                     }
                  }
               }
            }
         }
      }
   }
}

void PP2(string str) {
   int temp;
   int temp2, x;

   add = 0;
   if(PP>95) PP = 95;
   if(!str)
      input_to("PP2");
   else  if (str == "**" ) {
     write("Please enter '**' again to abort, or anything else to restart your skills");
     input_to("ABORT_RESTART2");
   } else {
      if(sscanf(str,"%d",add) != 1) {
         write("Please enter a number:");
         input_to("PP2");
      }
      else {
         if(add < 0) {
            write("Please input again -- 0 or more:");
            input_to("PP2");
         }
         else {
            if(add > 15) {
               write("Please input again -- 15 or less:");
               input_to("PP2");
            }
            else {
               if((PP+add)>95) {
                  write("Please input again -- skills may not exceed 95:");
                  input_to("PP2");
               }
               else {
                  PP+=add;
                  count_points+=add;
                  if(TP->is_class("bard")) {
                     write("Please enter addition to Detect noise:");
                     input_to("DN2");
                  }
                  else {
                     write("Please enter addition to Open locks:");
                     input_to("OL2");
                  }
               }  
            }
         }
      }
   }
}

void OL2(string str) {
   int temp;
   int temp2, x;

   if(OL>95) OL = 95;
   add = 0;
   if(!str)
      input_to("OL2");
   else  if (str == "**" ) {
     write("Please enter '**' again to abort, or anything else to restart your skills");
     input_to("ABORT_RESTART2");
   } else {
      if(sscanf(str,"%d",add) != 1) {
         write("Please enter a number:");
         input_to("OL2");
      }
      else {
         if(add < 0) {
            write("Please input again -- 0 or more:");
            input_to("OL2");
         }
         else {
            if(add > 15) {
               write("Please input again -- 15 or less:");
               input_to("OL2");
            }
            else {
               if((OL+add)>95) {
                  write("Please input again -- skills may not exceed 95:");
                  input_to("OL2");
               }
               else {
                  OL+=add;
                  count_points+=add;
                  write("Please enter addition to Find/remove traps:");
                  input_to("FRT2");
               }
            }
         }
      }
   }
}

void FRT2(string str) {
   int temp;
   int temp2, x;

   if(FRT>95) FRT = 95;
   add = 0;
   if(!str)
      input_to("FRT2");
   else  if (str == "**" ) {
     write("Please enter '**' again to abort, or anything else to restart your skills");
     input_to("ABORT_RESTART2");
   } else {
      if(sscanf(str,"%d",add) != 1) {
         write("Please enter a number:");
         input_to("FRT2");
      }
      else {

         if(add < 0) {
            write("Please input again -- 0 or more:");
            input_to("FRT2");
         }
         else {
            if(add > 15) {
               write("Please input again -- 15 or less:");
               input_to("FRT2");
            }
            else {
               if((FRT+add)>95) {
                  write("Please input again -- skills may not exceed 95:");
                  input_to("FRT2");
               }
               else {
                  FRT+=add;
                  count_points+=add;
                  write("Please enter addition to Move silently:");
                  input_to("MS2");
               }
            }
         }
      }
   }
}

void MS2(string str) {
   int temp;
   int temp2, x;

   if(MS>95) MS = 95;
   add = 0;
   if(!str)
      input_to("MS2");
   else  if (str == "**" ) {
     write("Please enter '**' again to abort, or anything else to restart your skills");
     input_to("ABORT_RESTART2");
   } else {
      if(sscanf(str,"%d",add) != 1) {
         write("Please enter a number:");
         input_to("MS2");
      }
      else {
         if(add < 0) {
            write("Please input again -- 0 or more:");
            input_to("MS2");
         }
         else {
            if(add > 15) {
               write("Please input again -- 15 or less:");
               input_to("MS2");
            }
            else {
               if((MS+add)>95) {
                  write("Please input again -- skills may not exceed 95:");
                  input_to("MS2");
               }
               else {
                  MS+=add;
                  count_points+=add;
                  write("Please enter addition to Hide in shadows:");
                  input_to("HIS2");
               }
            }
         }
      }
   }
}

void HIS2(string str) {
   int temp;
   int temp2, x;

   if(HIS>95) HIS = 95;
   add = 0;
   if(!str)
      input_to("HIS2");
   else  if (str == "**" ) {
     write("Please enter '**' again to abort, or anything else to restart your skills");
     input_to("ABORT_RESTART2");
   } else {
      if(sscanf(str,"%d",add) != 1) {
         write("Please enter a number:");
         input_to("HIS2");
      }
      else {
         if(add < 0) {
            write("Please input again -- 0 or more:");
            input_to("HIS2");
         }
         else {
            if(add > 15) {
               write("Please input again -- 15 or less:");
               input_to("HIS2");
            }
            else {
               if((HIS+add)>95) {
                  write("Please input again -- skills may not exceed 95:");
                  input_to("HIS2");
               }
               else {
                  HIS+=add;
                  count_points+=add;
                  write("Please enter addition to Detect noise:");
                  input_to("DN2");
               }
            }
         }
      }
   }
}

void DN2(string str) {
   int temp;
   int temp2, x;

   if(DN>95) DN = 95;
   add = 0;
   if(!str)
      input_to("DN2");
   else  if (str == "**" ) {
     write("Please enter '**' again to abort, or anything else to restart your skills");
     input_to("ABORT_RESTART2");
   } else {
      if(sscanf(str,"%d",add) != 1) {
         write("Please enter a number:");
         input_to("DN2");
      }
      else {
         if(add < 0) {
            write("Please input again -- 0 or more:");
            input_to("DN2");
         }
         else {
            if(add > 15) {
               write("Please input again -- 15 or less:");
               input_to("DN2");
            }
            else {
               if((DN+add)>95) {
                  write("Please input again -- skills may not exceed 95:");
                  input_to("DN2");
               }
               else {
                  DN+=add;
                  count_points+=add;
                  write("Please enter addition to Climb walls:");
                  input_to("CW2");
               }
            }
         }

      }
   }
}

void CW2(string str) {
   int temp;
   int temp2, x;

   if(CW>95) CW = 95;
   add = 0;
   if(!str)
      input_to("CW2");
   else if (str == "**" ) {
     write("Please enter '**' again to abort, or anything else to restart your skills");
     input_to("ABORT_RESTART2");
   } else {
      if(sscanf(str,"%d",add) != 1) {
         write("Please enter a number:");
         input_to("CW2");
      }
      else {
         if(add < 0) {
            write("Please input again -- 0 or more:");
            input_to("CW2");
         }
         else {
            if(add > 15) {
               write("Please input again -- 15 or less:");
               input_to("CW2");
            }
            else {
               if((CW+add)>95) {
                  write("Please input again -- skills may not exceed 95:");
                  input_to("CW2");
               }
               else {
                  CW+=add;
                  count_points+=add;
                  write("Please enter addition to Read languages:");
                  input_to("RL2");
               }
            }
         }
      }
   }
}

void RL2(string str) {
   int temp;
   int temp2, x;

   if(RL>95) RL = 95;
   add = 0;
   if(!str)
      input_to("RL2");
   else if (str == "**" ) {
     write("Please enter '**' again to abort, or anything else to restart your skills");
     input_to("ABORT_RESTART2");
   } else {
      if(sscanf(str,"%d",add) != 1) {
         write("Please enter a number:");
         input_to("RL2");
      }
      else {
         if(add < 0) {
            write("Please input again -- 0 or more:");
            input_to("RL2");
         }
         else {
            if(add > 15) {
               write("Please input again -- 15 or less:");
               input_to("RL2");
            }
            else {
               if((RL+add)>95) {
                  write("Please input again -- skills may not exceed 95:");
                  input_to("RL2");
               }
               else {
                  RL+=add;
                  count_points+=add;
                  if(count_points > 15 && TP->is_class("bard") || (count_points > 30)) {
		    //init_vars();
                     if(TP->is_class("bard"))
                        write("You have exceeded the maximum number of points: 15.");
                     else
                        write("You have exceeded the maximum number of points: 30.");           
		     // write("Please reconsider your additions and reenter them.");
                     //count_points = 0;
                     //write("Please enter your additions to Pick pockets");
                     //input_to("PP2");
		     write("Please enter '**' to abort, or anything else to restart your skills");
		     input_to("ABORT_RESTART2");
		     return;
                  } else {
                     TP->set_thief_skill("pick pockets",PP);
                     TP->set_thief_skill("open lock",OL);
                     TP->set_thief_skill("find/remove traps",FRT);
                     TP->set_thief_skill("move silently",MS);
                     TP->set_thief_skill("hide in shadows",HIS);
                     TP->set_thief_skill("detect noise",DN);
                     TP->set_thief_skill("climb walls",CW);
                     TP->set_thief_skill("read languages",RL);
                     write("Thieves' skills advancement complete.");
                     TP->set_advanced(((int)TP->query_advanced()-1));       
                     TO->remove();
                  }
               }
            }
         }
      }
   }
}
