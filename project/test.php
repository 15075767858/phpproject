<?php
        $fp = fopen("../../userinfo.txt", "r");
        echo "<div id='data' ";
        while (!feof($fp)) {
            echo fgets($fp);
        }
        echo "</div>";
        fclose($fp);
        ?>
