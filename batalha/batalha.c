void battle_finder ( t_node* root ) {

   if ( root->left != NULL ) {

   /*Batalha acontece */
   /*Preenche root com vencedor*/
   return;

   }

   battle_finder ( root->left );
   battle_finder ( root->right );
   
   return;
}

int player_battle ( t_node* player, t_node* enemy ) {

   

}
