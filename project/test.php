<?php
        $fp = fopen("../../bac_config.txt", "r");
        echo "<div id='data'>";
        while (!feof($fp)) {
            echo fgets($fp);
        }
        echo "</div>";
        fclose($fp);
        ?>