<li id='nav_[field:global name=autoindex runphp="yes"]@me=@me+1;[/field:global]' style='width:134px;' ><a href='{dede:field name='typeurl'/}' 0 title='{dede:field name='typename'/}' class='hover-none nav'><span>{dede:field name='typename'/}</span></a>
          <dl>
            {dede:channel type='son' row='4' currentstyle="
            <dd><a href='~typelink~' ~rel~><span>~typename~</span></a></dd>
            "}
            <dd><a href='[field:typeurl/]' title='[field:typename/]' >[field:typename/]</a></dd>
            {/dede:channel}
          </dl>
        </li>