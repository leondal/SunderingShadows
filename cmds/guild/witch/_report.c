int cmd_report(string str) {
  
  int hip, hip2, sta, sta2, mag, mag2;

  hip=(int)this_player()->query_hp();
  hip2=(int)this_player()->query_max_hp();
  sta=(int)this_player()->query_sp();
  sta2=(int)this_player()->query_max_sp();
  mag=this_player()->query_mp();
  mag2=this_player()->query_max_mp();

  write(
"You report:  hp "+hip+"/"+hip2+" sp "+sta+"/"+sta2+" mp "+mag+"/"+mag2); 
  say(this_player()->query_cap_name()+
" reports:  hp "+hip+"/"+hip2+" sp "+sta+"/"+sta2+" mp "+mag+"/"+mag2); 
  return 1;
   }

