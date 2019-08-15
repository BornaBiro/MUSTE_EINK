extern String txt;
extern int xpos;
extern int ypos;
extern int xPosPic;
extern int yPosPic;

String s = "<head>"
           "<title>e-radionica Muste e-paper display</title>"

           "<style type='text/css'>"

           "textarea {"
           "width: 300px;"
           "height: 5em;"
           "}"

           "select, textarea, input[type=radio] {"
           "  font-size: 150%;"
           "}"

           "input[type=number] {"
           "  font-size: 150%;"
           "  width: 100px;"
           "}"

           "t1 {"
           "  font-size: 150%;"
           "  font-weight: bold;"
           "}"

           "</style>"

           "</head>"

           "<body><form action='/string/' method='get' target='_self'><t1>Insert string that you want to display:</t1><br><textarea autofocus maxlength = '100' rows = '7' cols = '30' name = 'input1'>Write some text!</textarea><br>"
           "<t1>Select position of text<br>X = </t1><input type = 'number' name = 'xpos' value = '" + (String)(xpos) + "' maxLength = '3'><br>"
           "<t1>Y = </t1><input type = 'number' name = 'ypos' value = '" + (String)(ypos - 280) + "' maxLength = '3'><br><br><br><br>"

           "<t1>Select icon</t1><br>"
           "<input type = 'radio' name = 'icon' value = '0' checked><t1>No Icon</t1><br>"
           "<input type = 'radio' name = 'icon' value = '1'><t1>e-radionica logo</t1><br>"
           "<input type = 'radio' name = 'icon' value = '2'><t1>Soldering Iron</t1><br>"
           "<input type = 'radio' name = 'icon' value = '3'><t1>MUSTE logo</t1><br>"
           "<input type = 'radio' name = 'icon' value = '4'><t1>Smile</t1><br><br>"

           "<t1>Select position of icon<br>X = </t1><input type = 'number' name = 'xposIcon' value = '" + (String)(xPosPic) + "' maxLength = '3'><br>"
           "<t1>Y = </t1><input type = 'number' name = 'yposIcon' value = '" + (String)(yPosPic - 280) + "' maxLength = '3'><br><br>"
           "<input type='submit' value='Send to display!'></form></body></html>";
