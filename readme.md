# Projet-de-Magni-Borel

**Projet-de-Magni-Borel** est un système de gestion des présences du personnel au sein de la **DEREPOSTEL-OUEST**. Ce projet vise à automatiser le contrôle des présences en utilisant un système d'authentification par empreinte digitale. Le système est conçu pour améliorer la productivité en évitant les méthodes manuelles de vérification de présence, qui sont inefficaces et consommatrices de temps.

## 📋 Table des Matières

- [Description de l'Existant](#description-de-lexistant)
- [Critique de l'Existant](#critique-de-lexistant)
- [Proposition de la Solution](#proposition-de-la-solution)
- [Modélisation du Système](#modélisation-du-système)
- [Outils Utilisés](#outils-utilisés)
- [Fonctionnalités Principales](#fonctionnalités-principales)
- [Installation et Configuration](#installation-et-configuration)
- [Licence](#licence)
- [Crédits](#crédits)

## 📝 Description de l'Existant

Au sein de **DEREPOSTEL-OUEST**, la gestion des présences est effectuée manuellement par la secrétaire, qui doit faire le tour des bureaux pour vérifier la présence du personnel. Ce processus est non seulement chronophage mais réduit également l'efficacité de la secrétaire et, par extension, la productivité de l'entreprise.

## ❗ Critique de l'Existant

Le contrôle manuel des présences présente plusieurs inconvénients :
- **Temps consommé** : La secrétaire doit se déplacer fréquemment pour vérifier la présence du personnel, ce qui ralentit son travail.
- **Productivité réduite** : La gestion manuelle des présences diminue l'efficacité globale de l'entreprise.
- **Sécurité** : Le système actuel ne garantit pas la sécurité et la confidentialité des données du personnel.

## 💡 Proposition de la Solution

Pour résoudre ces problèmes, un **système d'authentification par empreinte digitale** a été conçu. Ce système permet de :
- **Enregistrer** : Chaque employé est enregistré en utilisant son empreinte digitale unique.
- **Authentifier** : Les empreintes digitales sont utilisées pour vérifier la présence des employés, garantissant une haute sécurité et confidentialité.
- **Rechercher** : Le système permet de rechercher et de lister tous les employés présents pendant une période donnée.

## 🛠 Modélisation du Système

La modélisation du système a été réalisée en utilisant la méthode **MERISE**, une méthode d'analyse et de conception de systèmes d'information. MERISE permet de séparer les données et les traitements en différents modèles conceptuels et physiques.

### Règles de Gestion Métier

- Chaque personnel est identifié par une empreinte digitale convertie en identifiant unique.
- Un personnel est caractérisé par ses nom, prénom, âge, et sexe.
- Un personnel peut occuper un ou plusieurs postes.
- Un poste est attribué à un seul personnel.
- Un personnel peut effectuer un ou plusieurs mouvements à des dates spécifiques.

## 🛠️ Outils Utilisés

### Composants Électroniques

- **Carte Arduino UNO** : Carte de prototypage rapide pour connecter capteurs et actionneurs.
- **Lecteur d'Empreinte Digitale** : Module pour enregistrer et identifier des empreintes digitales.
- **LEDs et Résistances** : Composants pour signalisation visuelle et contrôle du courant électrique.

### Langages de Programmation

- **HTML/CSS** : Pour structurer et styliser les pages web.
- **Python, PHP, JavaScript, SQL, Arduino** : Pour le développement du backend et du frontend.

### Logiciels

- **Arduino IDE** : Pour programmer la carte Arduino.
- **Python** : Pour envoyer les données d'authentification à la base de données.
- **Visual Studio Code** : Éditeur de texte principal.
- **Google Chrome** : Navigateur web pour tester l'application.
- **XAMPP** : Pour exécuter le code PHP et gérer la base de données MySQL.
- **MySQL/PHPMyAdmin** : Pour la gestion et l'administration des bases de données.

## 🌟 Fonctionnalités Principales

- **Enregistrement des Employés** : Ajouter de nouveaux employés avec leurs empreintes digitales.
- **Authentification** : Vérifier la présence des employés via leurs empreintes digitales.
- **Recherche et Rapport** : Rechercher les présences pour une période donnée.

## 🖥️ Installation et Configuration

1. **Cloner le dépôt** : `git clone https://github.com/niedjo/Projet-de-Magni-Borel.git`
2. **Configurer la base de données** : Importer le fichier `bd_personel.sql` dans MySQL.
3. **Configurer les paramètres du serveur** : Modifier les paramètres de connexion dans les fichiers PHP.
4. **Déployer le code** : Utiliser XAMPP pour déployer le code PHP sur un serveur local.

## 📄 Licence

Ce projet est protégé par les droits d'auteur. Toute utilisation non autorisée du code est interdite.

## 👥 Crédits

Projet développé par **Magni Borel** et **Niedjo Kuitche** pour **DEREPOSTEL-OUEST**.
