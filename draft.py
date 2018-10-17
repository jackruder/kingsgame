SYMBOLS = {'w':{'pawn': "♙", 'rook' : "♖", 'knight' : "♘", 'bishop' : "♗", 'king' : "♔", 'queen' : "♕" }, 'b' : {'pawn' : "♟", 'rook' : "♜", 'knight' : "♞", 'bishop' : "♝", 'king' : "♚", 'queen' : "♛" }}
E = (1,0)
W = (-1,0)
N = (0,1)
S = (0,-1)
NE = (1,1)
SE = (1,-1)
SW = (-1,-1)
NW = (-1,1)
STARTING = {'wpawn1': (0,1), 'wpawn2': (1,1), 'wpawn3': (2,1), 'wpawn4': (3,1), 'wpawn5': (4,1), 'wpawn6': (5,1), 'wpawn7': (6,1), 'wpawn8': (7,1), 'wknight1': (1,0), 'wknight2': (6,0), 'wbishop1': (2,0), 'wbishop2': (5,0), 'wrook1': (0,0), 'wrook2': (7,0), 'wking1': (4,0), 'wqueen1': (3,0), 'bpawn1': (0,6), 'bpawn2': (1,6), 'bpawn3': (2,6), 'bpawn4': (3,6), 'bpawn5': (4,6), 'bpawn6': (5,6), 'bpawn7': (6,6), 'bpawn8': (7,6), 'bknight1': (1,7), 'bknight2': (6,7), 'bbishop1': (2,7), 'bbishop2': (5,7), 'brook1': (0,7), 'brook2': (7,7), 'bking1': (4,7), 'bqueen1': (3,7)}

'''

static char characters[32] =
{
	'♖','♘','♗','♕','♔','♗','♘','♖', //white major and minor
	'♙','♙','♙', '♙', '♙', '♙','♙','♙', // white pawns
	'♟','♟','♟','♟','♟','♟','♟','♟', //black pawns
	'♜','♞','♝','♛','♚','♝','♞','♜' //black major and minor
};



'''

class board(object):
  def __init__(self):
    global E, W, N, S, NE, SE, SW, NW
    self.squares = {}
    self.pieces = {} #container of pieces
    self.turn = None
    self.gensquares()
    self.makepieces()

  def gensquares(self):
    rows = '12345678'
    files = 'abcdefgh'
    for f in files:
      self.squares[files.index(f)] = {} # initializes the storage of squares
      for r in rows:
        name = f+r  #algebraic notation names
        if (files.index(f)+int(r)) % 2 == 0: #determines if black or white based on sum of indexes
          color = 'white'
        else:
          color = 'black'
        self.squares[files.index(f)][int(r)-1] = square(color,name) #instantiation of square
  
  def makepieces(self):
      '''
      initalizes all pieces with null locations
      each piece is stored in self.pieces
      '''
      for c in ['white','black']: 
        for p in range(8): 
          name = c[0] + 'pawn' + str(p+1)
          paw = pawn(c,name,self)
          self.pieces[name] = paw
        for kn in range(2):
          name = c[0] + 'knight' + str(kn + 1)
          knigh = knight(c,name,self)
          self.pieces[name] = knigh
        for b in range(2):
          name = c[0] + 'bishop' + str(b + 1)
          bisho = bishop(c,name,self)
          self.pieces[name] = bisho
        for r in range(2):
          name = c[0] + 'rook' + str(r + 1)
          roo = rook(c,name,self)
          self.pieces[name] = roo
        kin = king(c,(c[0]+'king1'),self)
        quee = queen(c,(c[0]+'queen1'),self)
        self.pieces[(c[0]+'king1')] = kin
        self.pieces[(c[0]+'queen1')] = quee

  def incheck(self,color):
    for p in self.pieces:
      piece = self.pieces[p]
      if piece.color != color:
        if piece.canseeking() == False:
          pass
        else:
          return True
    return False   #makes sure an output is given if no pieces of opposite color are on board

  def placepieces(self):
    for name in self.pieces:
      piece = self.pieces[name]
      piece.move(STARTING[name])


  def textboard(self):
        output = ""
        output += "   a | b | c | d | e | f | g | h |\n"
        for r in range(7,-1,-1):
            output += ("-"*36)
            output += '\n'
            output += (str(r + 1) + "| ")
            for f in range(0,8):
                if self[(f,r)].piece != None:
                  piece = self[(f,r)].piece.char
                else: 
                  piece = ' '
                output += (piece +' | ')
            output += '\n'
        output += ("-"*36)
        return output

  def __str__(self):
    return self.textboard()
  
  @staticmethod
  def algconvert(t):
    f = t[0]
    r = t[1]
    files = 'abcdefgh'
    i = files.index(f)
    return (i,int(r)-1)
  
  
  def __getitem__(self,f):
    '''
    allows indexing of the board in the form self(tuple), which returns the square object
    or
    allows indexing of the piece in the form self(str)
    which returns the piece at the algebraic location specified
    '''
    if type(f)== int:
      return self.squares[f]
    elif type(f) == tuple:
      return self.squares[f[0]][f[1]]
    elif type(f) == str:
      i = self.algconvert(f)
      return self.squares[i[0]][i[1]].piece
  
class square(object):
  def __init__(self, color, name):
    self.color = color
    self.name = name
    self.attacks = []
    self.piece = None
  def __repr__(self):
    return self.name
  def __str__(self):
    return self.name


class piece(object):
  def __init__(self, color,name,board):
    self.color = color
    self.name = name
    self.loc = None
    self.board = board
    self.char = SYMBOLS[self.name[0]][self.name[1:len(self.name)-1]]
  def __repr__(self):
    return self.name
  def __str__(self):
    return self.name
  
  @staticmethod
  def onboard(p):
    f = p[0]
    r = p[1]
    if f < 0:
      return False
    elif f >= 8:
      return False
    elif r < 0:
      return False
    elif r >= 8:
      return False
    else:
      return True
 
  def vacant(self,p):
    result = False
    if self.onboard(p):
      if self.board[p].piece == None or self.board[p].piece.color != self.color:
        result = True
    return result
 
  def ray(self, directions):    
    spaces = []
    pos = self.loc
    for d in directions:
      i = 1
      stop = False
      while not stop:
        pf = pos[0]+d[0]*i
        pr = pos[1]+d[1]*i
        if self.vacant((pf,pr)):
          spaces.append(self.board[(pf,pr)])
          i += 1
        else:
          stop = True
    return spaces
 
  def canseeking(self):
    if self.color == 'white':
      kc = 'b'
    if self.color == 'black':
      kc = 'w'
    otherking = self.board.pieces[kc + 'king1']
    for move in self.availablemoves():
      if self.board[move.name] != None:
        if self.board[move.name].name == otherking.name:      
          return True
        else: 
          return False

  def move(self, sq):
    current = self.loc
    if current != None:
      if self.board[sq].piece == None:
        self.board[current].piece = None
        self.board[sq].piece = self
      else: 
        self.board[current].piece = None
        self.board[sq].piece.loc = None
        self.board[sq].piece = self
    else:
      if self.board[sq].piece == None:
        self.board[sq].piece = self
      else: 
        self.board[sq].piece.loc = None
        self.board[sq].piece = self
    self.loc = sq

          


class pawn(piece):
  def availablemoves(self):
    if self.color == 'white':
      t = 1
      d = (0,1)
    elif self.color == 'black':
      t = 6
      d = (0,-1)
    moves = []
    pos = self.loc
    if pos[1] == t:
      newposr = pos[1]+2*d[1]
      if self.vacant((pos[0],newposr)):
        moves.append(self.board[(pos[0],newposr)])
    newposr = pos[1]+d[1]
    if self.vacant((pos[0],newposr)):
      moves.append(self.board[(pos[0],newposr)])
    for i in [-1, 1]:
      newposf = pos[0] + i
      newpos = (newposf,newposr)
      if self.onboard(newpos):
        if self.board[newpos].piece != None:
          if self.board[newpos].piece.color != self.color:
            moves.append(self.board[newpos])
    return moves

class bishop(piece):
  directions = [NW, SE, NE, SW]
  def availablemoves(self):
    moves = self.ray(self.directions)
    return moves

class rook(piece):
  directions = [N, S, E, W]
  def availablemoves(self): 
    moves = self.ray(self.directions)
    return moves

class queen(piece):
  directions = [N,E,W,S,NE,NW,SE,SW]
  def availablemoves(self):
    moves = self.ray(self.directions)
    return moves

class knight(piece):  
  directions = [(-2,1),(-2,-1),(2,1),(2,-1),(1,2),(-1,2),(1,-2),(-1,-2)]
  def availablemoves(self):
    results = []
    pos = self.loc
    for d in self.directions:
      newpos = (pos[0]+d[0],pos[1]+d[1])
      if self.vacant(newpos):
        results.append(self.board[newpos])
    return results  

class king(piece):
  directons = [N,S,W,E,NW,NE,SW,SE]
  def availablemoves(self):
    results = []
    pos = self.loc
    for d in self.directions:
      newpos = (pos[0]+d[0],pos[1]+d[1])
      if self.vacant(newpos):
        results.append(self.board[newpos])
    return results  

