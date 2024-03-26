## Chess Engine

Chess Engine created to explore the world of chess programming
  
Learning resources :

1. Bluefever Software   
https://www.youtube.com/watch?v=bGAfaepBco4&list=PLZ1QII7yudbc-Ky058TEaOstZHVbT-2hg&index=2&ab_channel=BluefeverSoftware  
2. ChessProgramming Wiki  
https://www.chessprogramming.org/Main_Page  

## Project Status

This project is currently in mid-stage development.  
Currently setting up search and evaluation.
 
## PROGRESS  
Board representation - Completed  
Parse FEN - Completed
Print board - Completed  
Check if a square was attacked by opposite side - Completed  
Move formatting - Completed 
  
### Move Generation - Completed 
  white pawn - Done  (including en passant)
  black pawn - Done  (including en passant)
  white/black knight - Done  
  white/black king - Done  
  white/black rook - Done
  white/black bishop - Done  
  white/black queen - Done  
  castling - Done
  all moves generation - Done  
  
### Make Move / Take Move - Done
  
### Perft Testing - PASSED

### Position evaluation - Done
For now, position evaluation consist of Piece-Square tables, at which the position of each pieces on the board are added. 
For instance, a more favourable pawn position would be in the center thus higher scores are given. If the pawn are not at the center, then scores are lower.
  
(https://www.chessprogramming.org/Simplified_Evaluation_Function)

### Preparation for Search function (Alpha Beta + MinMax/NegaMax Algorithm) - Done

### Implementation of Search function - In Progress
