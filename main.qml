import QtQuick 2.15
import QtQuick.Controls 2.15

import com.mycompany.qmlcomponents 1.0


ApplicationWindow {
    id: window

    visible: true
    visibility: Qt.application.arguments[1] === "-fs" ? "FullScreen" : "Windowed"
    width: 960
    height: 600

    title: qsTr("My App")



    Column {
        Button {
            id: addLinkButton
            text: "Add Sim Link"
            onClicked: {
                MainApp.createLink();
                console.log("Number of links after: " + MainApp.links.length);
                var x = MainApp.links[0];
                console.log(x);
                console.log(x.deviceName());
            }
        }
    }
}
