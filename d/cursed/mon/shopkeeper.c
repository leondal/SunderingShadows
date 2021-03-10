inherit "/std/vendor";                                                      
                                                                            
create() {                                                                  
   ::create();                                                              
   set_name("Ore");                                                    
   set_id( ({ "ore","shop keeper", "shopkeeper"}) );         
   set_short("Ore the pathetic Cursed Land's shop keeper.");             
   set("aggressive", 0);                                                    
   set_level(19);                                                           
   set_long(
@STOP
He is the oldest, grungiest, and most pathetic 
looking shop keeper you have ever seen.
He will be glad to sell you anything he possesses.
(%^YELLOW%^ The highlight of his life..%^RESET%^)                   
<help shop> will get you a list of shop commands.
STOP
);             
   set_languages( ({ "common" }) );                                         
   set_gender("male");                                                      
   set_alignment(5);                                                        
   set("race", "kobold");                                                    
   set_hd(19,1);                                                            
   set_body_type("human");                                                 
   set_storage_room("/d/shadow/room/city/gs_storage");                     
   set_property("no attack",1);                                            
                             
}                                                              
                                                                            
                                              
