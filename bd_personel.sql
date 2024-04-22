-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le : lun. 15 mai 2023 à 18:41
-- Version du serveur : 5.7.36
-- Version de PHP : 7.4.26

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `bd_personel`
--

-- --------------------------------------------------------

--
-- Structure de la table `personnel`
--

DROP TABLE IF EXISTS `personnel`;
CREATE TABLE IF NOT EXISTS `personnel` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nom` varchar(20) DEFAULT NULL,
  `prenom` varchar(50) NOT NULL,
  `sexe` varchar(50) DEFAULT NULL,
  `date` datetime NOT NULL,
  `poste` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `personnel`
--

INSERT INTO `personnel` (`id`, `nom`, `prenom`, `sexe`, `date`, `poste`) VALUES
(1, 'NIEDJO', ' Darren', ' masculin', '2023-05-14 15:45:51', ' PDG\r\n'),
(2, 'NIEDJO', ' Darren', ' masculin', '2023-05-14 16:04:02', ' PDG\r\n'),
(3, 'NIEDJO', ' Darren', ' masculin', '2023-05-14 16:04:24', ' PDG\r\n'),
(4, 'NIEDJO', ' Darren', ' masculin', '2023-05-14 16:05:02', ' PDG\r\n'),
(5, 'NIEDJO', ' Darren', ' masculin', '2023-05-14 16:13:26', ' PDG\r\n'),
(6, 'NIEDJO', ' Darren', ' masculin', '2023-05-14 16:14:09', ' PDG\r\n'),
(7, 'NIEDJO', ' Darren', ' masculin', '2023-05-14 16:14:18', ' PDG\r\n'),
(8, 'NIEDJO', ' Darren', ' masculin', '2023-05-14 16:15:53', ' PDG\r\n'),
(9, 'NIEDJO', ' Darren', ' masculin', '2023-05-15 15:14:41', ' PDG\r\n'),
(10, 'MAGNI', ' borel', ' masculin', '2023-05-15 15:36:29', ' Commercial\r\n'),
(11, 'MAGNI', ' borel', ' masculin', '2023-05-15 17:35:13', ' Commercial\r\n');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
