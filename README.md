# Tugas-Besar-STD-Multi-Linked-List-M-ke-N
Tugas Besar STD Mengenai Multi Linked List M ke N

Spesifikasi Umum
List parent adalah daftar trainer
List child adalah daftar pokemon
List relasi adalah pocket dari trainer
Pocket menunjuk ke pokemon yang dimiliki trainer
Maksimal pocket yang dimiliki trainer adalah enam
Node trainer berisi info, adrPocket, dan nextTrainer
Node pocket berisi adrPokemon, nextPocket
Node pokemon berisi info, dan nextPokemon
Info dari trainer adalah IdTrainer: string, nama: string, pokedexCompletion: array[0..150]of boolean
Info dari pokemon berisi IdPokemon: string, nama: string, type1: string, type2: string
Trainer mendapatkan pokemon dengan melempar pokeball

Spesikasi Teknis
Pokemon tersimpan dalam multidimentional array yang pada saat program dimulai akan membuat child list pokemon dengan addPokemon yang didalamnya berisi dan di loop sampai akhir array CreateNewPokemon, CreatePokemonNode, dan InsertLast.
Player dapat memasukan trainer baru dengan memasukan data
Akan ada fungsi checkPocket untuk mengecek apakah pocket masih bisa ditambah  atau tidak
Ketika dilakukan trading antar trainer, diperlukan deletePocket dan insertPocket

Spesifikasi Menu
Add Trainer
input id, nama
createNodeTrainer
insertLastTrainer

Show Trainer
show semua trainer (id dan nama) dan pokemon di pocketnya

Select Trainer
pilih trainer berdasarkan id

Show Trainer Detail
cek apakah ada trainer yang di select
show trainer id, name dan pokemon di pocket
show trainer pokedex

Catch Pokemon
cek apakah ada trainer yang di select
cek apakah pocket masih tersedia
jika tidak ada, konfirmasi buang pocket paling atas dengan deleteFirstPocket
RNG id pokemon
cek apakah id hasil ada di pocket
jika tidak duplikat, buat pocket dengan insertLastPoket

Trade Pokemon
cek apakah ada trainer yang di select (trainer 1)
insert id trainer yang akan di trade (trainer 2)
insert id pokemon trainer 1
cek id pokemon trainer 1 di pocket
cek duplikasi pokemon di trainer 2
insert id pokemon trainer 2
cek id pokemon trainer 2 di pocket
cek duplikasi pokemon di trainer 1
tunjuk pocket di trainer 1, ganti ke id pokemon trainer 2
tunjuk pocket di trainer 2, ganti ke id pokemon trainer 1

Show All Pokemon
show all pokemon dari info pokemon (151 biji)

exit
