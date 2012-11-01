function ExampleThisUi(ui) {
    this.ui = ui;
    this.CLICK_COUNT = 0;
    with(this.ui){
        lineEdit.text = "i'm runed";
        SomePush.clicked.connect(this, "SomeAction");
        checkBox_1.checked = true;
        checkBox_2.checked = false;

    }
}

ExampleThisUi.prototype.SomeAction = function() {
    this.CLICK_COUNT++;
    with(this.ui) {
        checkBox_1.checked = !checkBox_1.checked;
        checkBox_2.checked = !checkBox_2.checked;
    }
    this.ui.lineEdit.text = "Button clicked " + this.CLICK_COUNT + " times";
}
