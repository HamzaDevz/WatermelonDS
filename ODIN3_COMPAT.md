# Compatibilité Odin 3 : WatermelonDS (DS)

Notre propre liste de compatibilité, tenue d'après nos tests sur l'AYN Odin 3 (Snapdragon 8 Elite, Adreno 830) avec notre build de la branche `odin3`. Chaque test met à jour la ligne du jeu : statut, mesure, date et commit testé. Amont : https://github.com/SapphireRhodonite/WatermelonDS

## Échelle

| Statut | Sens |
|---|---|
| 🟢 Parfait | vu en partie, plein régime, aucun défaut vu |
| 🔵 Jouable | vu en partie, défauts mineurs |
| 🟡 Problèmes | vu en partie, défauts gênants (fps, graphismes, son) |
| 🟠 Menus/intro | démarre, pas encore vu en partie |
| 🔴 Ne marche pas | crash, écran noir ou blocage |
| ⚪ Non testé | présent sur la console, jamais lancé |

## Comment on teste

Labo commun `odin3-lab` (VM ARM64 pages 4 Ko + profil Vulkan de l'Adreno 830) pour le CPU et la logique, puis l'Odin 3 par adb pour le GPU, les fps et la chauffe.

## Jeux

| Jeu | Statut | Vu jusqu'à | Mesure | Notes | Testé le | Build |
|---|---|---|---|---|---|---|
| Crash of the Titans (France) | 🟢 | premier niveau (tutoriel de Cortex), 30 s en jeu après menus et cinématique | 16x Vulkan (4096x3072) : 60 fps, 0 frame perdue, GPU 3D 6,4 ms/frame, CPU rendu 2,1 ms ; 1x logiciel : 60 fps, 0 frame perdue | captures identiques à la VM du labo (même contenu, léger décalage d'animation) ; son non vérifié | 2026-10-22 | odin3 65637d5 |
| Final Fantasy IV (France) | 🟢 | cinématiques 3D d'ouverture (aéronef des Red Wings, Cecil), 2 min 10 après « Nouvelle partie » | 16x Vulkan (4096x3072) : 58-61 fps, 0 frame perdue, GPU 3D 6-12 ms/frame (p95 ≤ 13 ms), CPU rendu 1-8 ms ; 1x logiciel : 60 fps, 0 frame perdue | captures 1x identiques à la VM du labo (DSSIM moyen 0,011) ; texte en anglais (langue du firmware) ; son non vérifié | 2026-10-22 | odin3 65637d5 |
| Dragon Quest IX : Les Sentinelles du Firmament (France) | 🔵 | Chutes de l'Ange en 3D (premières quêtes du gardien), 4 min après le lancement d'une nouvelle partie | 16x Vulkan (4096x3072) : 60 fps aux Chutes de l'Ange, 0 frame perdue, GPU 3D 9-12 ms/frame (max 13,8 ms) ; une chute à 41 fps sur le ciel nuageux du prologue (GPU 3D 22,6 ms/frame, translucidité plein écran) ; 1x logiciel : 60 fps, 0 frame perdue | captures 1x identiques à la VM du labo (DSSIM moyen 0,0045) ; 3D sur l'écran du bas ; texte en anglais (langue du firmware) ; son non vérifié | 2026-10-22 | odin3 65637d5 |
