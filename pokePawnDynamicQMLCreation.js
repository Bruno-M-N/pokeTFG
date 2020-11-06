//pokePawnDynamicQMLCreation.js

// Dynamic QML Object Creation from JavaScript
// https://doc.qt.io/qt-5/qtqml-javascript-dynamicobjectcreation.html

// QML Advanced Tutorial 2 - Populating the Game Canvas
// https://doc.qt.io/qt-5/qtquick-tutorials-samegame-samegame2-example.html

var arrayTeam1 = []; //create a new empty array
var arrayTeam2 = []; //create a new empty array

function loadPokesFromFiles() {
    cppPageManagement.loadPokesFromFiles("data/TFG Pokemons Classical.bin");
}

function displayPokes() {
    console.log("displayPokes");
    loadPokesFromFiles();

    //Delete blocks from previous game
    var maxIndexArrayTeam1 = arrayTeam1.length;
    var maxIndexArrayTeam2 = arrayTeam2.length;
    for (var i = 0; i < maxIndexArrayTeam1; ++i) {
        if (arrayTeam1[i] !== null)
            arrayTeam1[i].destroy();
    }

    for (i = 0; i < maxIndexArrayTeam2; ++i) {
        if (arrayTeam2[i] !== null)
            arrayTeam2[i].destroy();
    }

    //Initialize arrays
    arrayTeam1 = cppPageManagement.getTeam1Pokes();
    maxIndexArrayTeam1 = arrayTeam1.length;
    arrayTeam2 = cppPageManagement.getTeam2Pokes();
    maxIndexArrayTeam2 = arrayTeam2.length;

    console.log("_____________");
    for (i = 0; i < maxIndexArrayTeam1; ++i) {
        console.log( i + ": " + arrayTeam1[i]);
        createDynamicQMLPokePawn(arrayTeam1[i]);
    }

    for (i = 0; i < maxIndexArrayTeam2; ++i) {
        console.log( i + ": " + arrayTeam2[i]);
        createDynamicQMLPokePawn(arrayTeam2[i]);
    }

}

function createDynamicQMLPokePawn(qpoke){
    component = Qt.createComponent("NodeGoal.qml");
}

//function func() {

//}
