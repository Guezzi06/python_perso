/* But de l'exo : Ecrire le(s) mot(s) pile au milieu de notre chaine de caracteres
 
   s prend les entrees sous forme de tableau -> s = notre chaine de caracteres
   t cree un tableau de tableau avec split, qui contient tous les mots
   s stocke le nombre de mots qu'il y a
   Si ce nombre est pair, on print les 2 mots du milieu
   sinon on print le seul mot du milieu
*/
s=input()
t=s.split()
s=len(t)
if s%2==0:
 print(t[int(s/2)-1]+t[int(s/2)])
else:
 print(t[int(s/2)])

/* But de l'exo : Trouver le nombre final au terme de x annees a partir d'une valeur initiale
   et une augmentation de 10% chaque annee
 
   on prend la 1ere entree -> valeur initiale que l'on multiplie par
   1.1 (augmentation de 10%) * le nombre x d'annees qu'on recupere sur la 2eme entree
*/
print(int(int(input())*(1.1)**int(input())))

/* But de l'exo : Calculer la valeur finale apres les depots et retraits effectues en banque

   On recupere nos 2 entrees (V.I et transactions) avec cette 1ere ligne
   On parcourt transactions nombre de fois nos differentes transactions
   la 3e ligne permet de creer un tab de tab ou chaque case aura une entree
   ex : input[0] correspondra a W ou D, input[1] correspondra a la valeur en question
*/
v, n = [int(i) for i in input().split()]
for i in range(n):
    inputs = input().split()
    transaction = inputs[0]
    amount = int(inputs[1])
    if transaction == "W":
        v -= amount
    else:
        v +=amount
print(v)

/* But de l'exo : Compter le nombre de consonnes et de voyelles  dans la chaine et return le + grand des 2
 
   astuce : creer une chaine de 'test' pour tester si tel caractere appartient a un des caracteres de cette chaine
   .lower permet de mettre tous les caracteres en minuscule
   astuce : mettre dans le print une condition de cette maniere
*/
a='bcdfghjklmnpqrstvwz'
b='aeiouy'
c=0
v=0
for i in input().lower():
 if i in a:c+=1
 elif i in b:v+=1
print('consonants' if c>v else 'vowels')

/* Astuce : 
   permet d'afficher les 2 premiers caracteres de la string 3 fois
*/
print(_str[:2] * 3)

/* But de l'exo :
 
   Entree : --__--__  Ecrire le mot correspondant a ce code -> - represente 1 et _ represente 0 en binaire
            -__-_---  Obtenir la valeur decimale et afficher le caractere correspondant
			-__--_-_
			...
*/
a,*y=open(0)
for x in y:print(end=chr(int(x.replace('-','1').replace('_','0'),2)))

/* pour debugger : mettre file=sys.stderr */
print(position, len(monsters_x), len(monsters_y), file=sys.stderr)

/* On peut changer la maniere dont on recoit les entrees 
   exemple : */
time = input()
	-> time = '15:45'
time = [int(x) for x in input().split(":")]
	-> time est un tableau de 2 int: t[0] = 15 et t[1] = 45

/* Mettre sur une 1ere ligne toutes les voyelles qu on croise et
   mettre sur une 2eme ligne toutes les consonnes qu on croise */
message = input()

v = ''
C = ''
for c in message:
    if c in 'aeiouyAEIOUY':
        v += c
    elif c == ' ': pass
    else :
        C += c

print(v)
print(C)

/* Enonce : n
            m
   Determiner si il est possible d ecrire une somme de m entiers en ordre strictement croissant
   egale a n. Si oui afficher la liste de ces entiers separee par des espaces.
   Si non afficher -1 */
k = int(input())
n = int(input())

# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

list_of_nums = list(range(1, n))
list_of_nums.append(k - sum(list_of_nums))
if list_of_nums[-1] < 1 or len(list_of_nums) > len(set(list_of_nums)):
    print(-1)
else:
    print(*list_of_nums)

/* Enonce : 10010101010010
   Remplacer tous les '01' par 0 et '10' par 1
                   et '00' par rien et '11' par rien
   Si au final il n'y a rien a afficher, afficher EMPTY
   Si le nombre de bits est impair, afficher ERROR
*/
s = input()
if len(s)%2:print('ERROR')
else:
    t=''
    for i in range(0,len(s),2):
        if s[i:i+2]=='01':t+='0'
        elif s[i:i+2]=='10':t+='1'
    if t:print(t)
    else:print('EMPTY')

/* Convertir l ecriture hex #FF0978 en 3 int distincts : FF, 09, 78
 */
print(int(color[1:3],16))
print(int(color[3:5],16))
print(int(color[5:7],16))

