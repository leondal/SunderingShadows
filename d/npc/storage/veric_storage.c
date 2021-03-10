inherit "/d/common/inherit/metal_storage.c";


void reset(){
   int i, j;
   ::reset();
   j = random(5)+5;
   for(i=0;i<j;i++){
      if (!present("wood "+i)) {
         new("/std/obj/wood")->move(this_object());
      }
   }
}
