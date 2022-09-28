function Initialize()
    -- add a new ame JINE chat here.
        a = {}
        a[1] = "stop crying idiot!!!"
        a[2] = "youre gonna make me cry too :("
        a[3] = "ugh that face pisses me off"
        a[4] = "im gonna punch you"
        a[5] = "you wont get out of this by crying!"
        a[6] = "ugh"
        a[7] = "i hate that sticker"
        a[8] = ";-;"
        a[9] = "spare me the tears."
        a[10] = "dont :( me ill punch you!!!"
end

function Update()
    math.randomseed(os.time())
    math.random(); math.random(); math.random()

-- Randomizes from the JINE chats.
    return a[math.random(1,#a)]
end