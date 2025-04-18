Vagrant.configure("2") do |config|
	#config.vm.define "hmi" do |hmi|
	#	hmi.vm.box = "uahccre/ScadaBR"
	#	hmi.vm.hostname = "hmi"
	#	hmi.vm.network "private_network", ip: "192.168.56.2"
	#	hmi.vm.provider "virtualbox" do |vb|
	#		vb.customize ["modifyvm", :id, "--groups", "/SmartInstallation"]
	#	end
	#end
	
	config.vm.define "PlcBenchmark" do |plc|
		plc.vm.box = "uahccre/OpenPLC"
		plc.vm.hostname = "PlcBenchmark"
		plc.vm.network "private_network", ip: "192.168.56.100"
		plc.vm.provider "virtualbox" do |vb|
			vb.customize ["modifyvm", :id, "--groups", "/SmartInstallation"]
		end
		# Copying the master-slave configuration into the Master webserver
		# plc.vm.provision "file", source: "ladderlogic/", destination: "/tmp/"
		# plc.vm.provision "shell", inline: "cp /tmp/ladderlogic/mbconfig.cfg /home/vagrant/OpenPLC_v3/webserver/mbconfig.cfg"
	end
end
