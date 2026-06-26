# IoT Based Wild Animal Intrusion Detection System

## Overview

This project presents an Internet of Things (IoT)-based Wild Animal Intrusion Detection System designed to protect agricultural fields from damage caused by wild animal attacks. The system is developed using Raspberry Pi 5, ESP32 microcontroller, TensorFlow Lite, and Firebase to provide an intelligent, real-time monitoring solution.
A camera connected to the Raspberry Pi continuously captures images and uses a TensorFlow Lite-based machine learning model to identify and classify wild animals entering the monitored area. Upon detecting an intrusion, the system automatically triggers deterrent mechanisms such as flashing lights and buzzer alarms to scare the animals away and minimize crop damage. 
The ESP32 module facilitates communication between different hardware components, while Firebase serves as a cloud platform for storing and synchronizing data in real time. 
Additionally, a companion Android application has been developed to enable farmers to remotely monitor intrusion events, receive instant notifications, and manually control the deterrent devices from anywhere, thereby enhancing the efficiency and reliability of agricultural field protection.

## Features

* Real-time wild animal detection
* TensorFlow Lite machine learning model
* Raspberry Pi-based processing
* ESP32-based control system
* Automatic deterrence mechanism
* Firebase integration
* Android application support
* SMS alert notifications
* Live video monitoring through Android app

## Detected Animal Classes

The custom TensorFlow Lite model is trained to detect:

* Wild Boar
* Elephant
* Tiger
* Leopard
* Monkey
* Fox
* Bison

### Human Class

Humans are included in the dataset as a separate class to reduce false detections and prevent unnecessary activation of deterrence mechanisms.

## Technologies Used

* Python
* TensorFlow Lite
* Raspberry Pi 5
* ESP32
* Firebase Realtime Database
* Android Studio
* Java

## Hardware Components

* Raspberry Pi 5
* ESP32
* HD Webcam
* Relay Module
* Buzzer
* LED Lights
* SIM800L GSM Module
* Lithium-Ion Battery

## Project Structure

docs/ → Project report

code/ → IoT source code

images/ → Hardware setup and software screenshots

## Team Members

* ABIYA MARIYAM ALEX
* M YADHU KRISHNA
* NANDANA BIJU
* SANIA SAJAN JOHN

## Academic Project

Providence College of Engineering, Chengannur

B.Tech Computer Science and Engineering (IoT & Cyber Security)

2024–2025

